#include "stdafx.h"

#ifdef CSGPPAINTER_EXPORTS
#define CSGPPAINTER_API __declspec(dllexport)
#else
#define CSGPPAINTER_API __declspec(dllimport)
#endif

#include "libGUIPainterDefine.h"


LibGUIPainter* gpObj;


extern "C" CSRENDERER_API int GPCreate()
{
	if (gpObj != NULL)
		delete gpObj;

	gpObj = new LibGUIPainter();
	return 0;
}

extern "C" CSRENDERER_API int GPDestroy()
{
	delete gpObj;
	return 0;
}

extern "C" CSRENDERER_API int GPInit()
{
	int iRet = gpObj->Initialize();
	return iRet;
}

extern "C" CSRENDERER_API int GPCalc(int iCalcID, double dUIDataArr[], int iUIDataArrSize)
{
	if (!gpObj->Validate(iCalcID))
		return GP_ERR_VALIDERROR;

	return gpObj->Calculate(dUIDataArr, iUIDataArrSize);
}

extern "C" CSRENDERER_API int GPPaint(int* retArr, int retArrSize)
{
	return gpObj->Paint(retArr, retArrSize);
}
