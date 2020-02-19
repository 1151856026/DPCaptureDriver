/********************************************************************
created:	2016/03/01
filename: 	ImageCapture\MDDCaptureDriver\BmpToJpg.h
file path:	ImageCapture\MDDCaptureDriver
file base:	BmpToJpg
file ext:	h
author:		aji

purpose:	BMP文件和JPG文件转换类
*********************************************************************
Release Note  :


********************************************************************/


#pragma once
#include <GdiPlus.h>
#include <GdiPlusEnums.h>

using namespace Gdiplus;
#pragma comment(lib, "gdiplus")


class LBmpToJpg
{
public:
	LBmpToJpg();
	virtual ~LBmpToJpg();

	//bool AddFont(const char *pSrcName, const char *pDstName, const char *pText, int iXpos, int iYpos);
	bool BMPToJPG(const char *pBmpFile, const char *pJpgFile, long iQuality);
	bool JPGToBMP(const char *pJpgFile, const char *pBmpFile);
	WCHAR *BStr2WStr(const char *pSource, int &iDstLen);
};


