
#pragma once

#include "CameraStd.h"


enum ID_SAMPLEAPP_CAMERA_TYPE
{
	ID_SAMPLEAPP_DP71 = 0,
	ID_SAMPLEAPP_DP72,
	ID_SAMPLEAPP_DP21,
	ID_SAMPLEAPP_DP26,
	ID_SAMPLEAPP_DP73,
	ID_SAMPLEAPP_DP80,
	ID_SAMPLEAPP_DP22,
	ID_SAMPLEAPP_DP27,
	ID_SAMPLEAPP_DP74,
	NUMBER_OF_CAMTYPE
};

// Live Infomation...
typedef struct
{
	TCHAR szDisplay[1024];
	long lWidth;
	long lHeight;
}CAMERA_LIVE_SIZE;

typedef struct
{
	TCHAR szDisplay[1024];
	CAM_LV_BINNING_MODE kLiveBinningMode;
}CAMERA_LIVE_BINNING_MODE;

typedef struct
{
	CArray< CAMERA_LIVE_SIZE > arSize;
	CArray< CAMERA_LIVE_BINNING_MODE > arBinning;
}CAMERA_LIVE_INFO;

// Sia Infomation...
typedef struct
{
	TCHAR szDisplay[1024];
	long lWidth;
	long lHeight;
	CAM_SIA_SHIFT_MODE kShiftMode;
}CAMERA_SIA_SIZE;

typedef struct
{
	TCHAR szDisplay[1024];
	CAM_SIA_BINNING_MODE kSiaBinningMode;
}CAMERA_SIA_BINNING_MODE;

typedef struct
{
	CArray< CAMERA_SIA_SIZE > arSize;
	CArray< CAMERA_SIA_BINNING_MODE > arBinning;
}CAMERA_SIA_INFO;


class CCameraInfo
{
public:
	CCameraInfo(void);
	virtual ~CCameraInfo(void);

	static ID_SAMPLEAPP_CAMERA_TYPE GetCameraType( char *pszCameraName );
	// Live Info. 
	static void GetSupportLiveInfo( ID_SAMPLEAPP_CAMERA_TYPE kCameraType, CAMERA_LIVE_INFO *pstLiveInfo );
	static DWORD GetMaxLiveFrameDataSize( ID_SAMPLEAPP_CAMERA_TYPE kCameraType );
	// Sia Info. 
	static void GetSupportSiaInfo( ID_SAMPLEAPP_CAMERA_TYPE kCameraType, CAMERA_SIA_INFO *pstSiaInfo );
	static DWORD GetMaxSiaFrameDataSize( ID_SAMPLEAPP_CAMERA_TYPE kCameraType );
};
