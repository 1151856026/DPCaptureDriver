#ifndef	___CAMERA_FACTORY_H___
#define	___CAMERA_FACTORY_H___

#include "CameraStd.h"

#ifdef __cplusplus
extern "C" {	///< only need to export C interface if
				/// used by C++ source code
#endif

////< @defgroup DPLibFunction DP Library Function
//@{

////< @defgroup SetUpTheCamera Set Up The Camera
//@{

CAM_OBJECT * WINAPI CAM_CreateCameraEx(char *pszCameraId, BOOL bSynchronized);
BOOL WINAPI CAM_DeleteCameraEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);
BOOL WINAPI CAM_EnumCameraEx( BOOL bSynchronized, char **ppCameraList, long lMaxCamera, long lMaxCharacter );
BOOL WINAPI CAM_SetLastErrorEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_ERROR kErrorType, void *pErr);
BOOL WINAPI CAM_GetLastErrorEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_ERROR *plError);
BOOL WINAPI CAM_InitCameraEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,void *pParam);
BOOL WINAPI CAM_OnRegisteredCallbackEx(CAM_OBJECT *pCameraObject,CAM_CALLBACK_ID kId,WPARAM wParam,LPARAM lParam,CAM_ERROR kError);
BOOL WINAPI CAM_RegisterCallbackEx(CAM_OBJECT *pCameraObject,PFCAM_CALLBACK pFunction, void *pUser); 
BOOL WINAPI CAM_GetRegisteredCallbackEx(CAM_OBJECT *pCameraObject, PFCAM_CALLBACK *ppFunction, void **ppUser);
BOOL WINAPI CAM_SetTimeoutEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwTime);
BOOL WINAPI CAM_GetTimeoutEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD *pdwTime);
BOOL WINAPI CAM_SetLightPathShutterStateEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_LIGHT_PATH_SHUTTER_STATE_EX kState);
BOOL WINAPI CAM_GetLightPathShutterStateEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, PCAM_LIGHT_PATH_SHUTTER_STATE_EX pkState);
BOOL WINAPI CAM_SetExternalTriggerConditionEx(CAM_OBJECT *pCameraObject,
												BOOL bSynchronized,
												BOOL bInputEnable,
												BOOL bInputPolarity,
												double dOutputOpenDelay,
												BOOL bOutputEnable,
												BOOL bOutputPolarity,
												BOOL bOutputLiveMode);

BOOL WINAPI CAM_GetExternalTriggerConditionEx(CAM_OBJECT *pCameraObject,
												BOOL bSynchronized,
												BOOL *pbInputEnable,
												BOOL *pbInputPolarity,
												double *pdOutputOpenDelay,
												BOOL *pbOutputEnable,
												BOOL *pbOutputPolarity,
												BOOL *pbOutputLiveMode);
BOOL WINAPI CAM_SetExternalTriggerStateEx(CAM_OBJECT *pCameraObject,
												BOOL bSynchronized,
												CAM_EXTERNAL_TRIGGER_STATE_EX kTrigger);
BOOL WINAPI CAM_GetExternalTriggerStateEx(CAM_OBJECT *pCameraObject,
												BOOL bSynchronized,
												CAM_EXTERNAL_TRIGGER_STATE_EX *pkTrigger);
BOOL WINAPI CAM_GetVirtualNameEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,
									char *pszName, DWORD dwLength,
									PCAM_VIRTUAL_LEVEL pkLevel);
BOOL WINAPI CAM_GetImageInformation(CAM_OBJECT *pCameraObject, BOOL bSynchronized, PCAM_IMAGE_INFO pImageInfo);

//@}

////< @defgroup AutoExposure Auto Exposure
//@{
BOOL WINAPI CAM_AE_SetAdjustmentEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lCoefficient);
BOOL WINAPI CAM_AE_GetAdjustmentEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plCoefficient);
BOOL WINAPI CAM_AE_RegisterEvaluateFunctionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, PFCAM_AE_EVALUATE_CALLBACK pEvalFunction, void *pUser);
BOOL WINAPI CAM_AE_SetRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, const CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_AE_GetRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_AE_SetLockEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AE_LOCK_STATE kAeLock);
BOOL WINAPI CAM_AE_GetLockEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AE_LOCK_STATE *pkAeLock);
BOOL WINAPI CAM_AE_SetTargetValueEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwTargetVal);
BOOL WINAPI CAM_AE_GetTargetValueEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD *pdwTargetVal);
BOOL WINAPI CAM_AE_GetExposedStatusEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AE_STATUS *pkAeStatus);
BOOL WINAPI CAM_AE_StopOneTimeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);

//@}

////< @defgroup ExposureCondition Exposure Condition
//@{
BOOL WINAPI CAM_EXP_SetModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_EXP_MODE kExpMode);
BOOL WINAPI CAM_EXP_GetModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_EXP_MODE *pkExpMode);
BOOL WINAPI CAM_EXP_SetAeShutterSpeedEx(CAM_OBJECT* pCameraObject,BOOL bSynchronized,
									CAM_RATIONAL* pShutterSpeed);
BOOL WINAPI CAM_EXP_GetAeShutterSpeedEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RATIONAL *pShutterSpeed);
BOOL WINAPI CAM_EXP_SetManualShutterSpeedEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_RATIONAL *pShutterSpeed);
BOOL WINAPI CAM_EXP_GetManualShutterSpeedEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized,CAM_RATIONAL *pShutterSpeed);
BOOL WINAPI CAM_EXP_SetIsoEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lIso);
BOOL WINAPI CAM_EXP_GetIsoEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,long *plIso);
BOOL WINAPI CAM_EXP_SetOneTimeAEConditionsEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lAppropriateExpCount, long lTimeOut);
BOOL WINAPI CAM_EXP_GetOneTimeAEConditionsEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long* plAppropriateExpCount, long* plTimeOut);
BOOL WINAPI CAM_EXP_SetGainedExposureModeEx(CAM_OBJECT *pCameraObject,
									BOOL bSynchronized,
									CAM_EXP_GAINED_EXPOSURE_MODE kGainedExposureMode);
BOOL WINAPI CAM_EXP_GetGainedExposureModeEx(CAM_OBJECT *pCameraObject,
									BOOL bSynchronized,
								 	CAM_EXP_GAINED_EXPOSURE_MODE *pkGainedExposureMode);
BOOL WINAPI CAM_EXP_SetCCDSensitivityModeEx(CAM_OBJECT *pCameraObject,
										BOOL bSynchronized,
									 	CAM_EXP_CCD_SENSITIVITY_MODE kMode);
BOOL WINAPI CAM_EXP_GetCCDSensitivityModeEx(CAM_OBJECT *pCameraObject,
										BOOL bSynchronized,
									 	CAM_EXP_CCD_SENSITIVITY_MODE *pkMode);
BOOL WINAPI CAM_EXP_SetRealExposureLimitEx(CAM_OBJECT* pCameraObject,
										BOOL bSynchronized,
										CAM_RATIONAL *pstExposureLimit);
BOOL WINAPI CAM_EXP_GetRealExposureLimitEx(CAM_OBJECT* pCameraObject,
										BOOL bSynchronized,
										CAM_RATIONAL *pstExposureLimit);

//@}

////< @defgroup Focus Focus
//@{
BOOL WINAPI CAM_FCS_GetIndicatorValueEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plIndicatorValue, long *plIndicatorMaxValue);
BOOL WINAPI CAM_FCS_GetRealIndicatorValueEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long* plRealFocusValue, long* plRealFocusMaxValue);
BOOL WINAPI CAM_FCS_GetRealIndicatorValue32Ex(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long *pulRealFocusValue, unsigned long *pulRealFocusMaxValue);
BOOL WINAPI CAM_FCS_SetRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, const CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_FCS_GetRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_FCS_ResetEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);
BOOL WINAPI CAM_FCS_StartEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);
BOOL WINAPI CAM_FCS_StopEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);

//@}

////< @defgroup WhiteBalance White Balance
//@{
BOOL WINAPI CAM_WB_CalibrateBalanceEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);
BOOL WINAPI CAM_WB_SetModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_WB_MODE kWbMode);
BOOL WINAPI CAM_WB_GetModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_WB_MODE *pwWbMode);
BOOL WINAPI CAM_WB_SetRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_WB_GetRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_WB_SetRGBGainEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,double dRed, double dGreen, double dBlue);
BOOL WINAPI CAM_WB_GetRGBGainEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, double *pdRed, double *pdGreen, double *pdBlue);

//@}

////< @defgroup BlackBalance Black Balance
//@{
BOOL WINAPI CAM_BB_CalibrateBalanceEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);
BOOL WINAPI CAM_BB_SetModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_BB_MODE  kBBMode);
BOOL WINAPI CAM_BB_GetModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_BB_MODE *pwBBMode);
BOOL WINAPI CAM_BB_SetRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_BB_GetRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_BB_SetRGBOffsetEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,short dRed, short sGreen, short sBlue);
BOOL WINAPI CAM_BB_GetRGBOffsetEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, short* pwRed, short* pwGreen, short* pwBlue);

//@}

////< @defgroup ImageProcess Image Process
//@{
BOOL WINAPI CAM_IP_SetOrientationEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_ORIENTATION kOrientation, long lAngle);
BOOL WINAPI CAM_IP_GetOrientationEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_ORIENTATION *pkOrientation, long *plAngle);
BOOL WINAPI CAM_IP_SetSharpnessEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_SHARPNESS kSharpness);
BOOL WINAPI CAM_IP_GetSharpnessEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_SHARPNESS *pkSharpness);
BOOL WINAPI CAM_IP_SetColorEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_COLOR_MODE kColorMode);
BOOL WINAPI CAM_IP_GetColorEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_COLOR_MODE *pkColorMode);
BOOL WINAPI CAM_IP_SetLuminanceLevelEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, const CAM_IP_LEVEL_ADJUST_EX *pLevelAdj);
BOOL WINAPI CAM_IP_GetLuminanceLevelEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_LEVEL_ADJUST_EX *pLevelAdj);
BOOL WINAPI CAM_IP_SetContrastModeEx(CAM_OBJECT* pCameraObject, BOOL bSynchronized, CAM_IP_CONTRAST_MODE kMode);
BOOL WINAPI CAM_IP_GetContrastModeEx(CAM_OBJECT* pCameraObject, BOOL bSynchronized, CAM_IP_CONTRAST_MODE *pkMode);
BOOL WINAPI CAM_IP_SetLutEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,short *asLUT[]);
BOOL WINAPI CAM_IP_GetLutEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,short *asLUT[]);
BOOL WINAPI CAM_IP_SetNoiseReductionModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_NOISE_REDUCTION kMode);
BOOL WINAPI CAM_IP_GetNoiseReductionModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_NOISE_REDUCTION *pkMode);
BOOL WINAPI CAM_IP_SetDarkImageTimesEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lTimes);
BOOL WINAPI CAM_IP_GetDarkImageTimesEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plTimes);
BOOL WINAPI CAM_IP_GetOBClampEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plClamp);
BOOL WINAPI CAM_IP_SetCustomBWCoefficientEx( CAM_OBJECT *pCameraObject, BOOL bSynchronized, double dR, double dG, double dB );
BOOL WINAPI CAM_IP_GetCustomBWCoefficientEx( CAM_OBJECT *pCameraObject, BOOL bSynchronized,double *pdR, double *pdG, double *pdB );
BOOL WINAPI CAM_IP_SetColorSpace( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_COLOR_SPACE_MODE kColorSpaceMode );
BOOL WINAPI CAM_IP_GetColorSpace( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_COLOR_SPACE_MODE *pkColorSpaceMode );


//@}

////< @defgroup LiveImage Live Image
//@{
BOOL WINAPI CAM_LV_SetImageSizeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lWidth, long lHeight);
BOOL WINAPI CAM_LV_GetImageSizeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plWidth, long *plHeight);
BOOL WINAPI CAM_LV_SetBinningModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_LV_BINNING_MODE kBinningMode);
BOOL WINAPI CAM_LV_GetBinningModeEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_LV_BINNING_MODE *pkBinningMode);
BOOL WINAPI CAM_LV_SetZoomEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,long lX, long lY, double dZoomRate);
BOOL WINAPI CAM_LV_GetZoomEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,long *plX, long *plY, double *pdZoomRate);
BOOL WINAPI CAM_LV_SetShiftBitsFor16Ex(CAM_OBJECT *pCameraObject,
										BOOL bSynchronized, long lShift);
BOOL WINAPI CAM_LV_GetShiftBitsFor16Ex(CAM_OBJECT *pCameraObject,
										BOOL bSynchronized, long* plShift);
BOOL WINAPI CAM_LV_StartMovieEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, BYTE *pbyMemory);
BOOL WINAPI CAM_LV_StopMovieEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);
BOOL WINAPI CAM_LV_GetMovieStateEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_LV_MOVIE_STATE *pkMovieState);
BOOL WINAPI CAM_LV_ContinueMovieEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, BYTE *pbyMemory);
BOOL WINAPI CAM_LV_SetBytesAChannelEx(CAM_OBJECT *pCameraObject,
										BOOL bSynchronized, long lBytes);
BOOL WINAPI CAM_LV_GetBytesAChannelEx(CAM_OBJECT *pCameraObject,
										 BOOL bSynchronized, long *plBytes);

//@}

////< @defgroup VideoRecoder Video Recoder
//@{
BOOL WINAPI CAM_REC_SetBinningModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_REC_BINNING_MODE kBinningMode);
BOOL WINAPI CAM_REC_GetBinningModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_REC_BINNING_MODE *pkBinningMode);
BOOL WINAPI CAM_REC_ContinueRecordEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, BYTE *pbyMemory);
BOOL WINAPI CAM_REC_SetImageSizeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lWidth, long lHeight);
BOOL WINAPI CAM_REC_GetImageSizeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plWidth, long *plHeight);
BOOL WINAPI CAM_REC_StartRecordEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long ulChannel, unsigned long ulTime, unsigned long ulFrameTime, CAM_REC_RECORD_MODE kMode, BYTE *pbyMemory, unsigned long ulMemorySize, char *pszFileName, CAM_REC_FORMAT kFormat, PCAM_DISK_SIZE_EX pstDiskFreeSpace);
BOOL WINAPI CAM_REC_GetRecordProgressEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long ulChannel, unsigned long *pulProgress, unsigned long *pulElapsedTime, unsigned long *pulTotalTime, unsigned long *pulUsedMemorySize, unsigned long *pulTotalMemorySize);
BOOL WINAPI CAM_REC_GetRecordStateEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long ulChannel, unsigned long *pulNumberOfRecordedFrame, unsigned long *pulNumberOfLostFrame, PCAM_DISK_SIZE_EX pstRecordedSize);
BOOL WINAPI CAM_REC_ResetRecordStateEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long ulChannel);
BOOL WINAPI CAM_REC_StopRecordEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long ulChannel, BOOL bDiscard);
BOOL WINAPI CAM_REC_SetTrimmingRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long ulChannel, const CAM_RECTANGLE_EX *prectTrimming);
BOOL WINAPI CAM_REC_GetTrimmingRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long ulChannel, CAM_RECTANGLE_EX *prectTrimming);
BOOL WINAPI CAM_REC_FlushBufferEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, unsigned long ulChannel, char *pszFileName);

//@}

////< @defgroup GettingStillImage Getting Still-Image
//@{
BOOL WINAPI CAM_SIA_SetPreCaptureModeEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_SIA_PRECAPTUREMODE kPreCaptureMode);
BOOL WINAPI CAM_SIA_GetPreCaptureModeEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_SIA_PRECAPTUREMODE *pkPreCaptureMode);
BOOL WINAPI CAM_SIA_SetAccumulateModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_SIA_ACCUMULATE_MODE kAccMode);
BOOL WINAPI CAM_SIA_GetAccumulateModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_SIA_ACCUMULATE_MODE *pkAccMode);
BOOL WINAPI CAM_SIA_SetAccumulateTimesEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lTimes);
BOOL WINAPI CAM_SIA_GetAccumulateTimesEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plTimes);
BOOL WINAPI CAM_SIA_SetBytesAChannelEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, long lBytes);
BOOL WINAPI CAM_SIA_GetBytesAChannelEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized,long *plBytes);
BOOL WINAPI CAM_SIA_SetShiftBitsFor16Ex(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lShift);
BOOL WINAPI CAM_SIA_GetShiftBitsFor16Ex(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plShift);
BOOL WINAPI CAM_SIA_SetImageSizeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,long lWidth, long lHeight);
BOOL WINAPI CAM_SIA_GetImageSizeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,long *plWidth, long *plHeight);
BOOL WINAPI CAM_SIA_SetBinningModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_SIA_BINNING_MODE kBinningMode);		//<<ADD,Jan/31/2003,KOTARO
BOOL WINAPI CAM_SIA_GetBinningModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_SIA_BINNING_MODE *pkBinningMode);	//<<ADD,Jan/31/2003,KOTARO
BOOL WINAPI CAM_SIA_SetTrimmingRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, const CAM_RECTANGLE_EX *prectTrimming);
BOOL WINAPI CAM_SIA_GetTrimmingRegionEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *prectTrimming);
BOOL WINAPI CAM_SIA_GetCaptureImageSizeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plImageWidth, long *plImageHeight, long *plPreCaptureImageWidth, long *plPreCaptureImageHeight);
BOOL WINAPI CAM_SIA_CaptureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, void *pvImage);
BOOL WINAPI CAM_SIA_StopEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);
BOOL WINAPI CAM_SIA_ContinueCaptureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, void *pvImage);
BOOL WINAPI CAM_SIA_GetCaptureProgressEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plCurrentFrameProgress, long *plCurrentFrame, long *plTotalFrame);

//@}

////< @defgroup EstimationTools Estimation Tools
//@{

// Estimation Tools : Set Up The Camera
BOOL WINAPI	CAM_GetVersionEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized,CAM_DEVICE_ID kDeviceId, char *pszVer);
BOOL WINAPI CAM_SetSerialNumberEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_DEVICE_ID kDeviceId, char *pszSerialNumber);
BOOL WINAPI CAM_GetSerialNumberEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_DEVICE_ID kDeviceId, char *pszSerialNumber);
BOOL WINAPI CAM_SetPowerStateEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_POWER_STATE kPowerState);
BOOL WINAPI CAM_GetPowerStateEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_POWER_STATE *pkPowerState);
BOOL WINAPI CAM_GetCCDTemperatureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, double *pdTemperature);
BOOL WINAPI CAM_GetOutSideTemperatureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, double *pdTemperature);
BOOL WINAPI CAM_SetCCDTargetTemperatureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lTemperature);
BOOL WINAPI CAM_GetCCDTargetTemperatureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plTemperature);
BOOL WINAPI CAM_IsCameraObjectValidEx(CAM_OBJECT *pCameraObject);
BOOL WINAPI CAM_GetTemperatureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_TEMPERATURE_TYPE_EX kType, double *pdTemperture);
BOOL WINAPI CAM_GetLightPathShutterCounterEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, unsigned long *pulCounter);
// Estimation Tools : Auto Exposure
BOOL WINAPI CAM_AE_GetAeValueEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD *pdwAeVal);
BOOL WINAPI CAM_AE_AvePixelsEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AREA_AVE_EX *pAreaAve);
// Estimation Tools : Exposure Condition
BOOL WINAPI CAM_EXP_SetIsoGainEx( CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lVGAGain, long lCDSGain = 3 );
BOOL WINAPI CAM_EXP_GetIsoGainEx( CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plVGAGain, long *plCDSGain = NULL );
// Estimation Tools : Focus
BOOL WINAPI CAM_FCS_AvePixelsEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AREA_AVE_EX *pAreaAve);
// Estimation Tools : White Balance
BOOL WINAPI CAM_WB_AvePixelsEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AREA_AVE_EX *pAreaAve);
// Estimation Tools : Black Balance
BOOL WINAPI CAM_BB_AvePixelsEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AREA_AVE_EX *pAreaAve);
// Estimation Tools : Image Process
BOOL WINAPI CAM_EST_Set3x4MatrixEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_EST_DECIMAL paMatrixCoefficeint[][4]);
BOOL WINAPI CAM_EST_Get3x4MatrixEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_EST_DECIMAL aMatrixCoefficeint[][4]);
BOOL WINAPI CAM_EST_SetChromaKeyMatrixEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_EST_DECIMAL aCoefficeint[][2]);
BOOL WINAPI CAM_EST_GetChromaKeyMatrixEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_EST_DECIMAL aCoefficeint [][2]);
BOOL WINAPI CAM_EST_SetSharpnessEffectEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, double dEffect);
BOOL WINAPI CAM_EST_GetSharpnessEffectEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, double *pdEffect);
BOOL WINAPI CAM_IP_SetProcessEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lIPProcBitPattern);
BOOL WINAPI CAM_IP_GetProcessEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plIPProcBitPattern);
// Estimation Tools : Live Image
BOOL WINAPI CAM_LV_SetCCDImageTypeEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_LV_CCD_IMAGE_TYPE kImageType);
BOOL WINAPI CAM_LV_GetCCDImageTypeEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_LV_CCD_IMAGE_TYPE *pkImageType);
// Estimation Tools : Getting Still-Image
BOOL WINAPI CAM_SIA_SetCCDImageTypeEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_SIA_CCD_IMAGE_TYPE kImageType);
BOOL WINAPI CAM_SIA_GetCCDImageTypeEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, CAM_SIA_CCD_IMAGE_TYPE *pkImageType);
BOOL WINAPI CAM_SIA_GetImageInformation(CAM_OBJECT *pCameraObject, BOOL bSynchronized, PCAM_SIA_IMAGE_INFO pImageInfo);
// Estimation Tools : Maintenance
BOOL WINAPI CAM_EST_SetEepromDataEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwOffsetAdrs, DWORD wDataSize, WORD *pwData);
BOOL WINAPI CAM_EST_GetEepromDataEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwOffsetAdrs, DWORD wDataSize, WORD *pwData);
BOOL WINAPI CAM_EST_SetEepromDataAllEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, WORD *pwData);
BOOL WINAPI CAM_EST_GetEepromDataAllEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, WORD* pwData);
BOOL WINAPI CAM_EST_SetMemoryDataEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,DWORD dwOffsetAdrs,DWORD dwDataSize, DWORD *pdwData);
BOOL WINAPI CAM_EST_GetMemoryDataEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwOffsetAdrs,DWORD dwDataSize,DWORD *pdwData);
BOOL WINAPI CAM_EST_GetDetailErrorEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_ERROR *plError, CAM_ERROR *pkErrorType);
BOOL WINAPI CAM_EST_SetCameraDebugRegEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_DEBUG_REGISTER_EX kDebugReg, WORD wAddress, WORD wParam);
BOOL WINAPI CAM_EST_GetCameraDebugRegEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_DEBUG_REGISTER_EX kDebugReg, WORD wAddress, WORD *pwParam);
BOOL WINAPI CAM_EST_SetCameraEx( CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwPRMID, WORD *pwData, long lSize );
BOOL WINAPI CAM_EST_GetCameraEx( CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwPRMID, WORD *pwData,long *plSize );
BOOL WINAPI CAM_EST_SetCameraEx2( CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwPRMID, WORD *pwData, long lSize, WORD wWriteAddress );
BOOL WINAPI CAM_EST_GetCameraEx2( CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwPRMID, WORD *pwData,long *plSize, WORD wReadAddress );
BOOL WINAPI CAM_EST_GetInternalParameterEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lType, long *plParam);
BOOL WINAPI CAM_EST_UpdateEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_EST_UPDATE_DATA *pstData);
BOOL WINAPI CAM_EST_GetFWMemoryDataEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,DWORD dwOffsetAdrs,DWORD dwDataSize, BYTE *pbyData);
BOOL WINAPI CAM_EST_GetFWCPUMemoryDataEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,DWORD dwOffsetAdrs,DWORD dwDataSize, BYTE *pbyData);
BOOL WINAPI CAM_EST_SetBehaviorModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_EST_BEHAVIOR_MODE kMode, DWORD dwData);
BOOL WINAPI CAM_EST_SetInstructCamera(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lInstID);

////< @defgroup DPLink Tools
//@{

// DPLink
BOOL WINAPI CAM_LNK_Open(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwRate);
BOOL WINAPI CAM_LNK_OpenEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwRate, DWORD dwFrameMode);
BOOL WINAPI CAM_LNK_Send(CAM_OBJECT *pCameraObject, BOOL bSynchronized, BYTE *pbyData, DWORD dwSize);
BOOL WINAPI CAM_LNK_Receive(CAM_OBJECT *pCameraObject, BOOL bSynchronized, BYTE *pbyData, DWORD *pdwSize);
BOOL WINAPI CAM_LNK_GetReceiveStatus(CAM_OBJECT *pCameraObject, BOOL bSynchronized, PCAM_LNK_STATUS pLnkStatus);
BOOL WINAPI CAM_LNK_GetSendStatus(CAM_OBJECT *pCameraObject, BOOL bSynchronized, PCAM_LNK_STATUS pLnkStatus);
BOOL WINAPI CAM_LNK_GetErrorStatus(CAM_OBJECT *pCameraObject, BOOL bSynchronized, PCAM_LNK_ERROR_STATUS pLnkErrStatus);
BOOL WINAPI CAM_LNK_Close(CAM_OBJECT *pCameraObject, BOOL bSynchronized);

// DP21
BOOL WINAPI CAM_InitializeSDK(void);
BOOL WINAPI CAM_TerminateSDK(void);
BOOL WINAPI CAM_Enum1394CameraEx(BOOL bSynchronized, char **ppCameraList, long lMaxCamera, long lMaxCharacter);
BOOL WINAPI CAM_AE_SetModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AE_MODE kAeMode);
BOOL WINAPI CAM_AE_GetModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AE_MODE *pkAeMode);
BOOL WINAPI CAM_WB_SetColorTemperatureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_WB_COLOR_TEMPERATURE kWbColorTemperature);
BOOL WINAPI CAM_WB_GetColorTemperatureEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_WB_COLOR_TEMPERATURE *pkWbColorTemperature);
BOOL WINAPI CAM_IP_SetImageTransferModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_TRANSFER_MODE kTransferMode);
BOOL WINAPI CAM_IP_GetImageTransferModeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_TRANSFER_MODE *pkTransferMode);
BOOL WINAPI CAM_GetImagerPixelSizeEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lWidth, long lHeight, double *pdXImageSize, double *pdYImageSize);
BOOL WINAPI CAM_WB_SetGainOtwbEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized);
BOOL WINAPI CAM_EST_SetCameraRegisterEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_REGISTER_EX kRegister, WORD wAddress, DWORD dwParam);
BOOL WINAPI CAM_EST_GetCameraRegisterEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_REGISTER_EX kRegister, WORD wAddress, DWORD *pdwParam);

// DP26
BOOL WINAPI CAM_LV_SetROI(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_LV_GetROI(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_REC_SetROI(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_REC_GetROI(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_SIA_SetROI(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_SIA_GetROI(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect);
BOOL WINAPI CAM_SIA_GetActualImageInfo(CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plWidth, long *plHeight, long *plBytesPerChannel, long *plNumberOfChannel);
BOOL WINAPI CAM_WB_SetYUVGainEx(CAM_OBJECT *pCameraObject, BOOL bSynchronized,double dY, double dU, double dV);
BOOL WINAPI CAM_WB_GetYUVGainEx(CAM_OBJECT *pCameraObject,BOOL bSynchronized, double *pdY, double *pdU, double *pdV);
BOOL WINAPI CAM_REC_SetWorkBuffer(CAM_OBJECT *pCameraObject, BOOL bSynchronized, void *pBuffer, DWORD dwBufferSize);

// DP73/DP80 - New Add API 
CAM_OBJECT * WINAPI CAM_CreateCameraEx2( char *pszCameraId, BOOL bSynchronized, BOOL  bSIABuffAttachMode = FALSE );
BOOL WINAPI CAM_SetRandomTriggerCondition( CAM_OBJECT *pCameraObject, BOOL bSynchronized, BOOL bTriggerType, BOOL bPolarity );
BOOL WINAPI CAM_GetRandomTriggerCondition( CAM_OBJECT *pCameraObject, BOOL bSynchronized, BOOL *pbTriggerType, BOOL *pbPolarity );
BOOL WINAPI CAM_AE_SetHistRegionEx( CAM_OBJECT *pCameraObject, BOOL bSynchronized, const CAM_RECTANGLE_EX *pRect );
BOOL WINAPI CAM_AE_GetHistRegionEx( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RECTANGLE_EX *pRect );
BOOL WINAPI CAM_AE_SetHistCoef( CAM_OBJECT *pCameraObject, BOOL bSynchronized, double dR, double dG, double dB );
BOOL WINAPI CAM_AE_GetHistCoef( CAM_OBJECT *pCameraObject, BOOL bSynchronized,double *pdR, double *pdG, double *pdB );
BOOL WINAPI CAM_AE_SetSFL2Param( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_AE_SFL2_MODE kSFL2Mode, double dThresholdPixelNumRatio, double dAllowableSaturatedPixelNumRatio );
BOOL WINAPI CAM_AE_SetAutoAETargetValueMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, BOOL bAuto );
BOOL WINAPI CAM_AE_GetAutoAETargetValueMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, BOOL *pbAuto );
BOOL WINAPI CAM_EXP_SetExposureRotation( CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwRotateCount, CAM_ROTATE_RATIONALS *pShutterSpeeds );
BOOL WINAPI CAM_EXP_GetExposureRotation( CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD *pdwRotateCount, CAM_ROTATE_RATIONALS *pShutterSpeeds );
BOOL WINAPI CAM_IP_SetAntiHalationMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_ANTI_HALATION_MODE kAntiHalationMode, long lAsymmetry, long lSaturation, long lStrength );
BOOL WINAPI CAM_IP_GetAntiHalationMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_ANTI_HALATION_MODE *pkAntiHalationMode, long *plAsymmetry, long *plSaturation, long *plStrength, CAM_IP_NOISE_SUPPRESSION_INFO *pNoiseSuppression );
BOOL WINAPI CAM_IP_SetDevNoiseReductionMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_DEV_NR_MODE kDevNRMode );
BOOL WINAPI CAM_IP_GetDevNoiseReductionMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_DEV_NR_MODE *pkDevNRMode );
BOOL WINAPI CAM_IP_SetBleachCorrectionMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_BLEACH_CORRECTION_MODE kBleachCorrectionMode );
BOOL WINAPI CAM_IP_GetBleachCorrectionMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_BLEACH_CORRECTION_MODE *pkBleachCorrectionMode );
BOOL WINAPI CAM_IP_IsAntiHalationAvailable( CAM_OBJECT *pCameraObject, BOOL bSynchronized, BOOL *pbAntiHalationAvalable );
BOOL WINAPI CAM_IP_IsDevNoiseReductionAvailable( CAM_OBJECT *pCameraObject, BOOL bSynchronized, BOOL *pbNoiseReductionAvalable );
BOOL WINAPI CAM_IP_Set8ColorAdjustmentMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_8COLOR_ADJUSTMENT_MODE k8ColorAdjustmentMode, WORD wRed, WORD wGreen, WORD wBlue, DWORD dwPhy );
BOOL WINAPI CAM_SIA_StartRandomTriggerCapture( CAM_OBJECT *pCameraObject, BOOL bSynchronized, void *pvImage );
BOOL WINAPI CAM_SIA_ContinueRandomTriggerCapture( CAM_OBJECT *pCameraObject, BOOL bSynchronized, void *pvImage );
BOOL WINAPI CAM_SIA_StopRandomTriggerCapture( CAM_OBJECT *pCameraObject, BOOL bSynchronized );
BOOL WINAPI CAM_SIA_SetImageSizeAndMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lWidth, long lHeight, CAM_SIA_SHIFT_MODE kShiftMode );
BOOL WINAPI CAM_SIA_GetImageSizeAndMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plWidth, long *plHeight, CAM_SIA_SHIFT_MODE *pkShiftMode );
BOOL WINAPI CAM_SIA_AttachWorkBuffer( CAM_OBJECT *pCameraObject, BOOL bSynchronized, size_t uArraySize, size_t* pBuffSizeArray, void**  ppBuffArray );
BOOL WINAPI CAM_SIA_DetachWorkBuffer( CAM_OBJECT *pCameraObject, BOOL bSynchronized );
BOOL WINAPI CAM_EST_GetWDRState( CAM_OBJECT *pCameraObject, BOOL bSynchronized, BOOL *pbWDRAvail );
BOOL WINAPI CAM_EST_GetShadingImageSize( CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plImageSize );
BOOL WINAPI CAM_EST_CreateBlackShadingCorrectionData( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RATIONAL *pShutterSpeed, void *pvBlackImage );
BOOL WINAPI CAM_EST_CreateWhiteShadingCorrectionData( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_RATIONAL *pShutterSpeed, void *pvWhiteImage, void *pvBlackImage );
BOOL WINAPI CAM_EST_ApplyShadingCorrectionData( CAM_OBJECT *pCameraObject, BOOL bSynchronized, void *pvWhiteImage, void *pvBlackImage );
BOOL WINAPI CAM_EST_SetAFEData( CAM_OBJECT *pCameraObject, BOOL bSynchronized, WORD wAdr, DWORD dwData );
BOOL WINAPI CAM_EST_GetFlsData( CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwAdr, WORD* pwData );
BOOL WINAPI CAM_GetImageInformation2( CAM_OBJECT *pCameraObject, BOOL bSynchronized, void* pHeader, void* pFooter );
BOOL WINAPI CAM_LNK_GetSendCount(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD* pdwCount);
BOOL WINAPI CAM_LNK_GetReceiveCount(CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD* pdwCount);
BOOL WINAPI CAM_SetDetectAndSetPixelDefectsDone(CAM_OBJECT *pCameraObject, BOOL bSynchronized);

// DP80 - New Add API
BOOL WINAPI CAM_IP_SetPixelDefectsMode(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_PIXEL_DEFECTS_MODE kPixelDefectsMode);
BOOL WINAPI CAM_IP_GetPixelDefectsMode(CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_PIXEL_DEFECTS_MODE *pkPixelDefectsMode);
BOOL WINAPI CAM_EST_SetAFEData2( CAM_OBJECT *pCameraObject, BOOL bSynchronized, WORD wAdr, DWORD dwData );
BOOL WINAPI CAM_SIA_StartSWTrigger( CAM_OBJECT *pCameraObject, BOOL bSynchronized );
BOOL WINAPI CAM_SIA_StopSWTrigger( CAM_OBJECT *pCameraObject, BOOL bSynchronized );

// DP22/DP27 - New Add API 
BOOL WINAPI CAM_IP_GetShadingDataSize( CAM_OBJECT *pCameraObject, BOOL bSynchronized, long *plSize );
BOOL WINAPI CAM_IP_CalcShadingData( CAM_OBJECT *pCameraObject, BOOL bSynchronized, DWORD dwBlackCount, void **ppBlackData, DWORD dwWhiteCount, void **ppWhiteData, void *pBlackCorrectData, void *pWhiteCorrectData );
BOOL WINAPI CAM_IP_SetShadingMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lIndex, CAM_IP_SHADING_MODE kShadingMode );
BOOL WINAPI CAM_IP_GetShadingMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_SHADING_MODE *pkShadingMode );
BOOL WINAPI CAM_IP_SetShadingDataToCamera( CAM_OBJECT *pCameraObject, BOOL bSynchronized, long lIndex, void *pBlackData, void *pWhiteData );

// DP74 - New Add API 2015/10/21
BOOL WINAPI CAM_IP_SetHdrMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, const CAM_IP_HDR_START_PARAM *pstHdrStartParam );
BOOL WINAPI CAM_IP_GetHdrMode( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_HDR_START_PARAM *pstHdrStartParam );
BOOL WINAPI CAM_IP_SetHdrParam( CAM_OBJECT *pCameraObject, BOOL bSynchronized, const CAM_IP_HDR_UPDATE_PARAM *pstHdrUpdateParam);
BOOL WINAPI CAM_IP_GetHdrParam( CAM_OBJECT *pCameraObject, BOOL bSynchronized, CAM_IP_HDR_UPDATE_PARAM *pstHdrUpdateParam);
BOOL WINAPI CAM_IP_IsGpuHdrSupported( CAM_OBJECT *pCameraObject, BOOL bSynchronized, BOOL *pbSupport);

// DP74 - New Add Private API 2015/12/08
BOOL WINAPI CAM_IP_SetHdrSetMergeExParams( CAM_OBJECT *pCameraObject, BOOL bSynchronized, int nMergeLessYgapMode, double dMergeTW, double dMergeThR, int nGainBit );
BOOL WINAPI CAM_IP_GetHdrSetMergeExParams( CAM_OBJECT *pCameraObject, BOOL bSynchronized, int *pnMergeLessYgapMode, double *pdMergeTW, double *pdMergeThR, int *pnGainBit );
BOOL WINAPI CAM_IP_SetHdrMergeExParams( CAM_OBJECT *pCameraObject, BOOL bSynchronized, double **padWp, double **padWeight );
BOOL WINAPI CAM_IP_GetHddMergeExParams( CAM_OBJECT *pCameraObject, BOOL bSynchronized, double **padWp, double **padWeight );
BOOL WINAPI CAM_IP_SetHdrSetCompressExParams( CAM_OBJECT *pCameraObject, BOOL bSynchronized, double *padToneCurveK, int nToneLUTMode, double dGamma, int *panColorAxisAngle, int *panYthreshold );
BOOL WINAPI CAM_IP_GetHdrSetCompressExParams( CAM_OBJECT *pCameraObject, BOOL bSynchronized, double *padToneCurveK, int *pnToneLUTMode, double *pdGamma, int *panColorAxisAngle, int *panYthreshold );
BOOL WINAPI CAM_IP_SetHdrCalcDetgExParams( CAM_OBJECT *pCameraObject, BOOL bSynchronized, double dCoeff2, double dCoeff1, double dCoeff0, double dMinDetg, double dMaxDetg );
BOOL WINAPI CAM_IP_GetHdrCalcDetgExParams( CAM_OBJECT *pCameraObject, BOOL bSynchronized, double *pdCoeff2, double *pdCoeff1, double *pdCoeff0, double *pdMinDetg, double *pdMaxDetg );
CAM_ERROR WINAPI CAM_CheckDeviceState();

//@}

//@}

#ifdef __cplusplus
}
#endif

#endif	//}} ___CAMERA_FACTORY_H___

