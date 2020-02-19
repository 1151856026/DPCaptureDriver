
// DPCaptureDriverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DPCaptureDriver.h"
#include "DPCaptureDriverDlg.h"
#include "afxdialogex.h"
#include "BmpToJpg.h"

#include "CameraFactory.h"		// for DPSDK API 
#pragma comment(lib,"CamDriver.lib")
char* szCameraName = "DP27";
#define WM_SAMPLE_APP_COMPLETED_LIVE_CAPTURE	WM_APP + 0x0001

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

enum
{
	IMAGE_TOP_DOWN = 0,
	IMAGE_BOTTOM_UP,
};

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDPCaptureDriverDlg 对话框




CDPCaptureDriverDlg::CDPCaptureDriverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDPCaptureDriverDlg::IDD, pParent)
	, m_pCameraObject(NULL)
	, m_bInitializeCpmplete(FALSE)
	, m_pbySiaImageBuffer(NULL)
	, m_lSiaWidth(0)
	, m_lSiaHeight(0)
	, m_pbyLvImageBuffer(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDPCaptureDriverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_IMAGE_AREA, m_stcImageArea);
}

BEGIN_MESSAGE_MAP(CDPCaptureDriverDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_OPEN, &CDPCaptureDriverDlg::OnBnClickedBtnOpen)
	ON_MESSAGE(WM_SAMPLE_APP_COMPLETED_LIVE_CAPTURE, &CDPCaptureDriverDlg::OnCompletedLiveCapture)
	ON_BN_CLICKED(IDC_BTN_CAPTURE, &CDPCaptureDriverDlg::OnBnClickedBtnCapture)
END_MESSAGE_MAP()


// CDPCaptureDriverDlg 消息处理程序

BOOL CDPCaptureDriverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDPCaptureDriverDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDPCaptureDriverDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		DrawImage();
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDPCaptureDriverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDPCaptureDriverDlg::OnBnClickedBtnOpen()
{
	BOOL bRet = FALSE;
	CAM_OBJECT *pCameraObject = NULL;
	CAM_ERROR kError = kCAM_NO_ERROR;

	//1.检测设备状态 
	kError = CAM_CheckDeviceState();
	if (kError != kCAM_NO_ERROR)
	{
		CString strMsg;
		strMsg.Format( _T("It occured connected camera. ErrorID:%d"), kError );
		DisplayErrorMessage(strMsg);
		return;
	}
	if (m_pCameraObject)
	{
		return;
	}

	try
	{
		//2.创建摄像头实例
		pCameraObject = CAM_CreateCameraEx(szCameraName,TRUE);
		if (pCameraObject == NULL)
		{
			throw FALSE;
		}
		//3.注册回调函数
		BOOL bRet = CAM_RegisterCallbackEx(pCameraObject,MyCallbackFunciton,this);
		if ( bRet != TRUE )
			throw bRet;
	
		//4.初始化摄像头
		m_bInitializeCpmplete = FALSE;
		bRet = CAM_InitCameraEx( pCameraObject, FALSE, kCAM_INITIALIZE_DEFAULT );
		if ( bRet != TRUE )
			throw bRet;
	
		//5.查询摄像头初始化是否完成
		while ( 1 )
		{
			Sleep( 10 );
			if ( m_bInitializeCpmplete )
				break;
		}
		//获取摄像头类型
		m_kCamType = CCameraInfo::GetCameraType( szCameraName );
		//设置Live参数
		{
			CAMERA_LIVE_INFO stLiveInfo;
			CCameraInfo::GetSupportLiveInfo( m_kCamType, &stLiveInfo );
			bRet = CAM_LV_SetImageSizeEx( pCameraObject, TRUE, stLiveInfo.arSize.GetAt(0).lWidth, stLiveInfo.arSize.GetAt(0).lHeight );
			if ( bRet != TRUE )
				throw bRet;
			bRet = CAM_LV_SetBinningModeEx( pCameraObject, TRUE, (CAM_LV_BINNING_MODE)stLiveInfo.arBinning.GetAt(0).kLiveBinningMode);
			if ( bRet != TRUE )
				throw bRet;
		}
		//设置Sia参数
		{
			CAMERA_SIA_INFO stSiaInfo;
			CCameraInfo::GetSupportSiaInfo( m_kCamType, &stSiaInfo );
			bRet = CAM_SIA_SetImageSizeAndMode( pCameraObject, TRUE, stSiaInfo.arSize.GetAt(0).lWidth, stSiaInfo.arSize.GetAt(0).lHeight, stSiaInfo.arSize.GetAt(0).kShiftMode );
			if ( bRet != TRUE )
				throw bRet;
			bRet = CAM_SIA_SetBinningModeEx( pCameraObject, TRUE, (CAM_SIA_BINNING_MODE)stSiaInfo.arBinning.GetAt(0).kSiaBinningMode );
			if ( bRet != TRUE )
				throw bRet;
		}
	
		m_pbyLvImageBuffer = new BYTE[ CCameraInfo::GetMaxLiveFrameDataSize( m_kCamType ) ];
		m_pbySiaImageBuffer = new BYTE[ CCameraInfo::GetMaxSiaFrameDataSize( m_kCamType ) ];
		m_pCameraObject = pCameraObject;
	}
	catch (...)
	{
		bRet = CAM_GetLastErrorEx( NULL, TRUE, &kError );
		if ( bRet == TRUE )
		{
			// 僄儔乕僐乕僪傪妋擣 
		}

		if ( pCameraObject )
			bRet = CAM_DeleteCameraEx( pCameraObject, TRUE );
		pCameraObject = NULL;

		if ( m_pbyLvImageBuffer )
			delete[] m_pbyLvImageBuffer;
		m_pbyLvImageBuffer = NULL;
		if ( m_pbySiaImageBuffer )
			delete[] m_pbySiaImageBuffer;
		m_pbySiaImageBuffer = NULL;
	}

}


void CDPCaptureDriverDlg::DisplayErrorMessage(LPCTSTR pszMsg)
{
	MessageBox( pszMsg, NULL, MB_OK | MB_ICONSTOP );
}


void CDPCaptureDriverDlg::MyCallbackFunciton(CAM_OBJECT* pCameraObject, CAM_CALLBACK_ID kID, WPARAM wParam, LPARAM lParam, CAM_ERROR kError, void * pUser)
{
	CDPCaptureDriverDlg *p = (CDPCaptureDriverDlg*)pUser;
	switch ( kID )
	{
	case kCAM_INITCAMERAEX:	
		{
			p->m_bInitializeCpmplete = TRUE;
		}
		break;
	case kCAM_1FRAMETRANSFEREX:
		{
			CAM_LV_IMAGE_INFO *pstCallbackInfo = (CAM_LV_IMAGE_INFO*)wParam;
			if ( kError != kCAM_NO_ERROR )
			{
				CString strMsg;
				strMsg.Format( _T("Lv(kCAM_1FRAMETRANSFEREX) Error Id:%d"), kError );
				p->DisplayErrorMessage( strMsg );
			}
			else
			{
				// Copy CAM_LV_IMAGE_INFO 
				if ( wParam != 0 )
					memcpy_s( &( p->m_stLvInfo ), sizeof( CAM_LV_IMAGE_INFO ), (void*)wParam, sizeof( CAM_LV_IMAGE_INFO ) );
				// Message post. 
				p->PostMessage( WM_SAMPLE_APP_COMPLETED_LIVE_CAPTURE, NULL, NULL );
			}
		}
		break;
	case kCAM_SIA_CAPTUREEX:
		{
			p->SetImage( p->m_pbySiaImageBuffer, p->m_lSiaWidth, p->m_lSiaHeight, 3 );
		}
		break;
	}
}

void* CreateBitmapHandle( int nWidth, int nHeight, int nBitCount, void** ppBits, int nLineAlignment )
{
	BITMAPINFOHEADER bmpInfo;
	ZeroMemory( &bmpInfo, sizeof( bmpInfo ) );
	bmpInfo.biSize = sizeof( bmpInfo );
	bmpInfo.biWidth = nWidth;
	if ( nLineAlignment == IMAGE_TOP_DOWN )
		bmpInfo.biHeight = -nHeight;
	else
		bmpInfo.biHeight = nHeight;
	bmpInfo.biBitCount = (WORD)nBitCount;
	bmpInfo.biPlanes = 1;
	HBITMAP hBitmap = ::CreateDIBSection( NULL, (LPBITMAPINFO)&bmpInfo, DIB_RGB_COLORS, ppBits, NULL, 0 );
	return hBitmap;
}

void CDPCaptureDriverDlg::SetImage(void * pImage, DWORD dwWidth, DWORD dwHeight, DWORD dwChannel,BOOL isCapture)
{
	if ( pImage == NULL )
		return;

	BOOL bNewImage = TRUE;	
	HBITMAP hBitmap = NULL;

	DIBSECTION dib;
	ZeroMemory( &dib, sizeof(dib) );
	if ( m_hBitmap )
		::GetObject( m_hBitmap, sizeof(dib), &dib );

	DWORD dwDstBytePerLine = ( dwWidth * dwChannel + 3 ) & ~3;
	if ( dib.dsBmih.biWidth == dwWidth &&
		dib.dsBmih.biHeight == dwHeight &&
		dib.dsBmih.biBitCount == dwChannel * 8 )
		bNewImage = FALSE;

	void *pBits = NULL;
	if ( bNewImage == TRUE )
	{
		hBitmap = (HBITMAP)CreateBitmapHandle( dwWidth, dwHeight, dwChannel * 8, &pBits, IMAGE_TOP_DOWN );
		if ( hBitmap == NULL )
			return;
	}
	else
	{
		pBits = dib.dsBm.bmBits;
	}

	DWORD dwSrcBytePerLine = dwWidth * dwChannel;
	for ( DWORD y = 0; y < dwHeight; ++y )
	{
		PBYTE pSrcPos = (PBYTE)pImage + y * dwSrcBytePerLine;
		PBYTE pDstPos = (PBYTE)pBits + y * dwDstBytePerLine;
		memcpy_s( pDstPos, dwDstBytePerLine, pSrcPos, dwSrcBytePerLine );
	}

	if ( bNewImage == TRUE )
	{
		if ( m_hBitmap )
			::DeleteObject( m_hBitmap );
		m_hBitmap = NULL;
		m_hBitmap = hBitmap;
	}

	CRect rcView;
	m_stcImageArea.GetWindowRect( rcView );
	ScreenToClient( rcView );
	InvalidateRect( rcView, FALSE );
}


LRESULT CDPCaptureDriverDlg::OnCompletedLiveCapture(WPARAM wParam, LPARAM lParam)
{
	// Draw Live Frame(8bit4ch) 
	SetImage( m_pbyLvImageBuffer, m_stLvInfo.dwWidth, m_stLvInfo.dwHeight, 4 );
	// Request next live frame. 
	BOOL bRet = FALSE;
	CString strMsg;
	bRet = CAM_LV_ContinueMovieEx( m_pCameraObject, FALSE, m_pbyLvImageBuffer );
	if ( bRet != TRUE )
	{
		// Check error code. 
		CAM_ERROR kErrorCode = kCAM_NO_ERROR;
		bRet = CAM_GetLastErrorEx( m_pCameraObject, TRUE, &kErrorCode );
		if ( bRet == TRUE )
		{
			if ( kErrorCode != kCAM_API_CALLED_IN_INVALID_STATE )
			{
				// Display error message. 
				strMsg.Format( _T("Lv(CAM_LV_ContinueMovieEx) Error Id:%d"), kErrorCode );
				DisplayErrorMessage( strMsg );
			}
		}
	}
	return 0;
}


void CDPCaptureDriverDlg::DrawImage(void)
{
	if ( m_hBitmap == NULL )
		return;

	CDC *pDC = m_stcImageArea.GetDC();

	DIBSECTION dib;
	ZeroMemory( &dib, sizeof(dib) );
	::GetObject( m_hBitmap, sizeof(dib), &dib );

	CRect rcClient;
	m_stcImageArea.GetClientRect( &rcClient );

	CBitmap cVirtualBitmap;
	cVirtualBitmap.CreateCompatibleBitmap( pDC, rcClient.Width(), rcClient.Height() );
	CDC cVirtualDC;
	cVirtualDC.CreateCompatibleDC( pDC );
	CBitmap* pOldBmp = cVirtualDC.SelectObject( &cVirtualBitmap );

	CDC cImageDC;
	cImageDC.CreateCompatibleDC( &cVirtualDC );
	cImageDC.SelectObject( CBitmap::FromHandle( m_hBitmap ) );

	cVirtualDC.SetStretchBltMode( COLORONCOLOR );

	CRect rcDiaplay( 0,0,0,0 );
	CRect rcImage( 0, 0, dib.dsBmih.biWidth, dib.dsBmih.biHeight );
	{
		double dImgRatioW = (double)rcImage.Width() / (double)rcImage.Height();
		double dPaintRatioW = (double)rcClient.Width() / (double)rcClient.Height();

		if ( dPaintRatioW > dImgRatioW )
		{
			DWORD dwFitHeight = rcClient.Height();
			DWORD dwFitWidth = (DWORD)( (double)dwFitHeight * dImgRatioW );
			rcDiaplay.left = ( rcClient.Width() - dwFitWidth ) / 2;
			rcDiaplay.right = rcDiaplay.left + dwFitWidth;
			rcDiaplay.top = 0;
			rcDiaplay.bottom = dwFitHeight;
		}
		else
		{
			DWORD dwFitWidth = rcClient.Width();
			DWORD dwFitHeight = (DWORD)( (double)dwFitWidth * ( 1.0 / dImgRatioW ) );
			rcDiaplay.left = 0;
			rcDiaplay.right = dwFitWidth;
			rcDiaplay.top = ( rcClient.Height() - dwFitHeight ) / 2;
			rcDiaplay.bottom = rcDiaplay.top + dwFitHeight;
		}
	}

	cVirtualDC.StretchBlt( rcDiaplay.left, rcDiaplay.top, rcDiaplay.Width(), rcDiaplay.Height(), &cImageDC, 0, 0, dib.dsBmih.biWidth, dib.dsBmih.biHeight, SRCCOPY );
	pDC->BitBlt( 0, 0, rcClient.Width(), rcClient.Height(), &cVirtualDC, 0, 0, SRCCOPY );

	cVirtualDC.SelectObject( pOldBmp );
	cVirtualDC.DeleteDC();
	cVirtualBitmap.DeleteObject();
	m_stcImageArea.ReleaseDC( pDC );
}

int SaveToBmp(LPBYTE ImageMem, long Width, long Height)
{
	BITMAPINFOHEADER bmih; 
	bmih.biSize =40;
	bmih.biBitCount = 24;
	bmih.biClrImportant =0;
	bmih.biClrUsed =0;
	bmih.biCompression = BI_RGB;
	bmih.biHeight = Height;
	bmih.biWidth = Width;
	bmih.biPlanes =1;
	bmih.biXPelsPerMeter =0;
	bmih.biYPelsPerMeter =0;
	bmih.biSizeImage = Width *Height * 3;

	BITMAPFILEHEADER hdr; 
	FILE* file;
	hdr.bfType = ((WORD) ('M' << 8) | 'B'); // is always "BM" 
	hdr.bfSize = 40+ bmih.biSizeImage + sizeof( hdr ); 
	hdr.bfReserved1 = 0; 
	hdr.bfReserved2 = 0; 
	hdr.bfOffBits = (DWORD) (sizeof( hdr )) + 40;// + nColors * sizeof(RGBQUAD)); // Write the file header 
	char* ImageBuf = new char[64];
	const char * fileName= "D:\\test.bmp";
	file = fopen(fileName,"w");
	fwrite(&hdr, 1, sizeof(hdr),file);
	fwrite(&bmih, 1, 40,file);
	fwrite(ImageMem, 1, bmih.biSizeImage,file);  
	fclose(file);
	return 0;
}

void CDPCaptureDriverDlg::OnBnClickedBtnCapture()
{
	BOOL bRet = FALSE;
	long lSiaWidth = 0, lSiaHeight = 0, lPreSiaWidth = 0, lPreSiaHeight = 0;
 	bRet = CAM_SIA_GetCaptureImageSizeEx( m_pCameraObject, TRUE, &lSiaWidth, &lSiaHeight, &lPreSiaWidth, &lPreSiaHeight );
	if ( bRet != TRUE )
	{
		// Get error info. 
		CAM_ERROR kError = kCAM_NO_ERROR;
		CAM_GetLastErrorEx( NULL, TRUE, &kError );
		// Display error info. 
		CString strMsg;
		strMsg.Format( _T("Error : CAM_SIA_GetCaptureImageSizeEx(%d)"), kError );
		DisplayErrorMessage( strMsg );
		return;
	}

	// Keep size info.
	m_lSiaWidth = lSiaWidth;
	m_lSiaHeight = lSiaHeight;

	// Still capture. 
	// -Async proc...
	bRet = CAM_SIA_CaptureEx( m_pCameraObject, FALSE, m_pbySiaImageBuffer );
	if ( bRet != TRUE )
	{
		// Get error info. 
		CAM_ERROR kError = kCAM_NO_ERROR;
		CAM_GetLastErrorEx( NULL, TRUE, &kError );
		// Display error info. 
		CString strMsg;
		strMsg.Format( _T("Error : CAM_SIA_CaptureEx(%d)"), kError );
		DisplayErrorMessage( strMsg );
		return;
	}

	SaveToBmp(m_pbySiaImageBuffer, m_lSiaWidth, m_lSiaHeight);


}
