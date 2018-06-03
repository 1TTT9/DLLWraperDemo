#pragma once
#include "stdafx.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

#define  PainterConfigFile "D:\\pc.xml"
#define  iNumOfPaintMAX 65536
#define  iNumOfCalcMAX 65536

enum 
{
	GP_ERR_NONE = 0,
	GP_ERR_CONFIGFILENOTFOUND = 1,
	GP_ERR_DATASIZEERROR = 2,
	GP_ERR_COUNTERERROR = 3,
	GP_ERR_VALIDERROR = 4
};


class LibGUIPainter
{
public:
	LibGUIPainter();
	virtual ~LibGUIPainter();
private:
	FileStorage fs;
	string gpPainterWidth;
	string gpPainterHeight;
	int iUIDataArrSizeDefault;
	int iNumOfPaint;
	int iNumOfCalc;
public:	
	int Initialize();
	bool Validate(int id);
	int Calculate(double dUIDataArr[], int iUIDataArrSize);
	int Paint(int retArr[], int retArrSize);
};