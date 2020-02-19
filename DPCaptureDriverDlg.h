
// DPCaptureDriverDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "CameraStd.h"
#include "CameraInfo.h"


// CDPCaptureDriverDlg 对话框
class CDPCaptureDriverDlg : public CDialogEx
{
// 构造
public:
	CDPCaptureDriverDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DPCAPTUREDRIVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void DisplayErrorMessage(LPCTSTR pszMsg);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOpen();
//protected:
	CAM_OBJECT *m_pCameraObject;
	static void CALLBACK MyCallbackFunciton(CAM_OBJECT* pCameraObject, CAM_CALLBACK_ID kID, WPARAM wParam, LPARAM lParam, CAM_ERROR kError, void * pUser);
	BOOL m_bInitializeCpmplete;
	CAM_LV_IMAGE_INFO m_stLvInfo;
	BYTE *m_pbySiaImageBuffer;
	BYTE *m_pbyLvImageBuffer;
	long m_lSiaWidth;
	long m_lSiaHeight;
	void SetImage(void * pImage, DWORD dwWidth, DWORD dwHeight, DWORD dwChannel,BOOL isCapture = FALSE); //True 为采图
	HBITMAP m_hBitmap;
	CStatic m_stcImageArea;
	afx_msg LRESULT OnCompletedLiveCapture(WPARAM wParam, LPARAM lParam);

protected:
	ID_SAMPLEAPP_CAMERA_TYPE m_kCamType;
	void DrawImage(void);
public:
	afx_msg void OnBnClickedBtnCapture();
};
