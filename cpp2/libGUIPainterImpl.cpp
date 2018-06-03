#include "stdafx.h"
#include <iterator>
#include <vector>
#include <fstream>
#include <iostream>


//#include <cmath>
#define M_PI 3.14159265358979323846

#include "libGUIPainterDefine.h"

using namespace std;
using namespace cv;

LibGUIPainter::LibGUIPainter() {
	cout << "constructor" << endl;
	gpPainterWidth = 300;
	gpPainterHeight = 300;
	iUIDataArrSizeDefault = 10;
	iNumOfPaint = 0;
	iNumOfCalc = 0;
}

LibGUIPainter::~LibGUIPainter() {

}

int LibGUIPainter::Initialize() 
{
	cout << endl << "Configuration File Reading: " << endl;
	fs.open(PainterConfigFile, FileStorage::READ);
	if (!fs.isOpened())
	{
		cout << "Failed to open " << PainterConfigFile << endl;
		return GP_ERR_CONFIGFILENOTFOUND;
	}
	fs["gpPainterWidth"] >> gpPainterWidth;
	fs["gpPainterHeight"] >> gpPainterHeight;
	fs["iUIDataArrSizeDefault"] >> iUIDataArrSizeDefault;
	return GP_ERR_NONE;
}

bool LibGUIPainter::Validate(int id) 
{
	return id == iNumOfCalc;
}

int LibGUIPainter::Calculate(double dUIDataArr[], int iUIDataArrSize)
{
	iNumOfCalc = (iNumOfCalc+1) % iNumOfCalcMAX + 1;

	if (iUIDataArrSize != iUIDataArrSizeDefault)
		return GP_ERR_DATASIZEERROR;

	vector<double> dataArr(dUIDataArr, dUIDataArr+iUIDataArrSize);
	for(size_t i=0; i<dataArr.size(); i+=2) 
		if (i<2)
		{
			gpPainterWidth = dataArr[i]*0.323634543590812 + dataArr[i+1]/22.912343432434;
		}
		else if (i<4 && i<6)
		{
			gpPainterHeight = dataArr[i]/22.912343432434 + dataArr[i+1]/0.323634543590812;
		}
		else
		{
			gpPainterWidth = dataArr[i] * M_PI /dataArr[i+1] ;
			gpPainterHeight = dataArr[i] * dataArr[i+1] / M_PI;
		}

	return GP_ERR_NONE;
}


int LibGUIPainter::Paint(int retArr[], int retArrSize) 
{
	iNumOfPaint = (iNumOfPaint+1) % iNumOfPaintMAX + 1;

	if (iNumOfPaint != iNumOfCalc)
		return GP_ERR_COUNTERERROR;

	if (retArrSize != 2)
		return GP_ERR_DATASIZEERROR;

	retArr[0] = gpPainterWidth;
	retArr[1] = gpPainterHeight;
	return GP_ERR_NONE;
}
