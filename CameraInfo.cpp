#include "StdAfx.h"
#include "CameraInfo.h"

CCameraInfo::CCameraInfo(void)
{
}

CCameraInfo::~CCameraInfo(void)
{
}

/**
//*****************************************************************************
// @brief	
// @param[in]	pszCameraName
// @return	
//****************************************************************************/
ID_SAMPLEAPP_CAMERA_TYPE CCameraInfo::GetCameraType( char *pszCameraName )
{
	ID_SAMPLEAPP_CAMERA_TYPE kType = NUMBER_OF_CAMTYPE;
	typedef struct
	{
		ID_SAMPLEAPP_CAMERA_TYPE kCameraType;
		char szCamera[256];
	}SAMPLEAPP_CAMERA_TABLE;
	SAMPLEAPP_CAMERA_TABLE stCameraTable[] = { { ID_SAMPLEAPP_DP71, "DP71" },
											   { ID_SAMPLEAPP_DP72, "DP72" },
											   { ID_SAMPLEAPP_DP21, "DP21" },
											   { ID_SAMPLEAPP_DP26, "DP26" },
											   { ID_SAMPLEAPP_DP73, "DP73" },
											   { ID_SAMPLEAPP_DP80, "DP80" },
											   { ID_SAMPLEAPP_DP22, "DP22" },
											   { ID_SAMPLEAPP_DP27, "DP27" },
											   { ID_SAMPLEAPP_DP74, "DP74" },};
	// テーブルから一致する名称をチェックする 
	for ( int i = 0; i < sizeof( stCameraTable ) / sizeof( SAMPLEAPP_CAMERA_TABLE ); ++i )
	{
		if ( strncmp( pszCameraName, stCameraTable[i].szCamera, strlen( stCameraTable[i].szCamera ) ) == 0 )
		{
			kType = stCameraTable[i].kCameraType;
			break;
		}
	}

	return kType;
}

/**
//*****************************************************************************
// @brief	
// @param[in]	kCameraType
// @param[out]	pstLiveInfo
//****************************************************************************/
void CCameraInfo::GetSupportLiveInfo( ID_SAMPLEAPP_CAMERA_TYPE kCameraType, CAMERA_LIVE_INFO *pstLiveInfo )
{
	switch( kCameraType )
	{
	case ID_SAMPLEAPP_DP21:
	case ID_SAMPLEAPP_DP73:
		{
			// Size 
			{
				CAMERA_LIVE_SIZE stSize = {0};
				// 1600x1200 
				stSize.lWidth = 1600;
				stSize.lHeight = 1200;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
				// 800x600 
				stSize.lWidth = 800;
				stSize.lHeight = 600;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_LIVE_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstLiveInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstLiveInfo->arBinning.Add( stBinning );
			}
		}
		break;
	case ID_SAMPLEAPP_DP71:
	case ID_SAMPLEAPP_DP72:
	case ID_SAMPLEAPP_DP80:
		{
			// Size 
			{
				CAMERA_LIVE_SIZE stSize = {0};
				// 1360x1024 
				stSize.lWidth = 1360;
				stSize.lHeight = 1024;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
				// 680x512 
				stSize.lWidth = 680;
				stSize.lHeight = 512;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
				// 340x256 
				stSize.lWidth = 340;
				stSize.lHeight = 256;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_LIVE_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstLiveInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstLiveInfo->arBinning.Add( stBinning );
				// 4x4 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_4x4;
				_stprintf_s( stBinning.szDisplay, _T("4x4") );
				pstLiveInfo->arBinning.Add( stBinning );
			}
		}
		break;
	case ID_SAMPLEAPP_DP22:
		{
			// Size 
			{
				CAMERA_LIVE_SIZE stSize = {0};
				// 1920x1440 
				stSize.lWidth = 1920;
				stSize.lHeight = 1440;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
				// 960x600 
				stSize.lWidth = 960;
				stSize.lHeight = 720;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_LIVE_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstLiveInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstLiveInfo->arBinning.Add( stBinning );
			}
		}
		break;
	case ID_SAMPLEAPP_DP26:
	case ID_SAMPLEAPP_DP27:
		{
			// Size 
			{
				CAMERA_LIVE_SIZE stSize = {0};
				// 2448x1920 
				stSize.lWidth = 2448;
				stSize.lHeight = 1920;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
				// 1224x960 
				stSize.lWidth = 1224;
				stSize.lHeight = 960;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_LIVE_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstLiveInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstLiveInfo->arBinning.Add( stBinning );
			}
		}
		break;
	case ID_SAMPLEAPP_DP74:
		{
			// Size 
			{
				CAMERA_LIVE_SIZE stSize = {0};
				// 1920x1200 
				stSize.lWidth = 1920;
				stSize.lHeight = 1200;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
				// 960x600 
				stSize.lWidth = 960;
				stSize.lHeight = 600;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstLiveInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_LIVE_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstLiveInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kLiveBinningMode = kCAM_LV_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstLiveInfo->arBinning.Add( stBinning );
			}
		}
		break;
	}
}

/**
//*****************************************************************************
// @brief	
// @param[in]	kCameraType
// @return	
//****************************************************************************/
DWORD CCameraInfo::GetMaxLiveFrameDataSize( ID_SAMPLEAPP_CAMERA_TYPE kCameraType )
{
	DWORD dwDataSize = 0;

	switch ( kCameraType )
	{
	case ID_SAMPLEAPP_DP71:
	case ID_SAMPLEAPP_DP72:
	case ID_SAMPLEAPP_DP80:
		dwDataSize = 1360 * 1024 * 4;	// W * H * 4ch 
		break;
	case ID_SAMPLEAPP_DP74:
		dwDataSize = 1920 * 1200 * 4;	// W * H * 4ch 
		break;
	case ID_SAMPLEAPP_DP21:
	case ID_SAMPLEAPP_DP73:
		dwDataSize = 1600 * 1200 * 4;	// W * H * 4ch 
		break;
	case ID_SAMPLEAPP_DP22:
		dwDataSize = 1920 * 1440 * 4;	// W * H * 4ch 
		break;
	case ID_SAMPLEAPP_DP26:
	case ID_SAMPLEAPP_DP27:
		dwDataSize = 2448 * 1920 * 4;	// W * H * 4ch 
		break;
	}

	return dwDataSize;
}

/**
//*****************************************************************************
// @brief	
// @param[in]	kCameraType
// @param[out]	pstSiaInfo
//****************************************************************************/
void CCameraInfo::GetSupportSiaInfo( ID_SAMPLEAPP_CAMERA_TYPE kCameraType, CAMERA_SIA_INFO *pstSiaInfo )
{
	switch( kCameraType )
	{
	case ID_SAMPLEAPP_DP71:
	case ID_SAMPLEAPP_DP72:
	case ID_SAMPLEAPP_DP80:
		{
			// Size 
			{
				CAMERA_SIA_SIZE stSize = {0};
				// 1360x1024 
				stSize.lWidth = 1360;
				stSize.lHeight = 1024;
				stSize.kShiftMode = kCAM_SIA_NO_SHIFT_MODE;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
				// 680x512 
				stSize.lWidth = 680;
				stSize.lHeight = 512;
				stSize.kShiftMode = kCAM_SIA_NO_SHIFT_MODE;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
				// 340x256 
				stSize.lWidth = 340;
				stSize.lHeight = 256;
				stSize.kShiftMode = kCAM_SIA_NO_SHIFT_MODE;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_SIA_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstSiaInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstSiaInfo->arBinning.Add( stBinning );
				// 4x4 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_4x4;
				_stprintf_s( stBinning.szDisplay, _T("4x4") );
				pstSiaInfo->arBinning.Add( stBinning );
			}
		}
		break;
	case ID_SAMPLEAPP_DP21:
	case ID_SAMPLEAPP_DP73:
		{
			// Size 
			{
				CAMERA_SIA_SIZE stSize = {0};
				// 1600x1200 
				stSize.lWidth = 1600;
				stSize.lHeight = 1200;
				stSize.kShiftMode = kCAM_SIA_NO_SHIFT_MODE;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
				// 800x600 
				stSize.lWidth = 800;
				stSize.lHeight = 600;
				stSize.kShiftMode = kCAM_SIA_NO_SHIFT_MODE;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_SIA_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstSiaInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstSiaInfo->arBinning.Add( stBinning );
			}
		}
		break;
	case ID_SAMPLEAPP_DP22:
		{
			// Size 
			{
				CAMERA_SIA_SIZE stSize = {0};
				// 1920x1200 
				stSize.lWidth = 1920;
				stSize.lHeight = 1440;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
				// 960x600 
				stSize.lWidth = 960;
				stSize.lHeight = 720;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_SIA_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstSiaInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstSiaInfo->arBinning.Add( stBinning );
			}
		}
		break;
	case ID_SAMPLEAPP_DP26:
	case ID_SAMPLEAPP_DP27:
		{
			// Size 
			{
				CAMERA_SIA_SIZE stSize = {0};
				// 1920x1200 
				stSize.lWidth = 2448;
				stSize.lHeight = 1920;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
				// 960x600 
				stSize.lWidth = 1224;
				stSize.lHeight = 960;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_SIA_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstSiaInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstSiaInfo->arBinning.Add( stBinning );
			}
		}
		break;
	case ID_SAMPLEAPP_DP74:
		{
			// Size 
			{
				CAMERA_SIA_SIZE stSize = {0};
				// 1920x1200 
				stSize.lWidth = 1920;
				stSize.lHeight = 1200;
				stSize.kShiftMode = kCAM_SIA_NO_SHIFT_MODE;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
				// 960x600 
				stSize.lWidth = 960;
				stSize.lHeight = 600;
				stSize.kShiftMode = kCAM_SIA_NO_SHIFT_MODE;
				_stprintf_s( stSize.szDisplay, _T("%dx%d"), stSize.lWidth, stSize.lHeight );
				pstSiaInfo->arSize.Add( stSize );
			}
			// Binning 
			{
				CAMERA_SIA_BINNING_MODE stBinning = {0};
				// OFF 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_OFF;
				_stprintf_s( stBinning.szDisplay, _T("OFF") );
				pstSiaInfo->arBinning.Add( stBinning );
				// 2x2 
				stBinning.kSiaBinningMode = kCAM_SIA_BINNING_2x2;
				_stprintf_s( stBinning.szDisplay, _T("2x2") );
				pstSiaInfo->arBinning.Add( stBinning );
			}
		}
		break;
	}
}

/**
//*****************************************************************************
// @brief	
// @param[in]	kCameraType
// @return	
//****************************************************************************/
DWORD CCameraInfo::GetMaxSiaFrameDataSize( ID_SAMPLEAPP_CAMERA_TYPE kCameraType )
{
	DWORD dwDataSize = 0;

	switch ( kCameraType )
	{
	case ID_SAMPLEAPP_DP71:
	case ID_SAMPLEAPP_DP72:
	case ID_SAMPLEAPP_DP80:
		dwDataSize = 1360 * 1024 * 3;	// W * H * 3ch 
		break;
	case ID_SAMPLEAPP_DP74:
		dwDataSize = 1920 * 1200 * 3;	// W * H * 3ch 
		break;
	case ID_SAMPLEAPP_DP21:
	case ID_SAMPLEAPP_DP73:
		dwDataSize = 1600 * 1200 * 3;	// W * H * 3ch 
		break;
	case ID_SAMPLEAPP_DP22:
		dwDataSize = 1920 * 1440 * 3;	// W * H * 3ch 
		break;
	case ID_SAMPLEAPP_DP26:
	case ID_SAMPLEAPP_DP27:
		dwDataSize = 2448 * 1920 * 3;	// W * H * 3ch 
		break;
	}

	return dwDataSize;
}
