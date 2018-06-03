// ForCSharpCalc.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#ifdef FORCSHARPCALC_EXPORTS
#define FORCSHARPCALC_API __declspec(dllexport)
#else
#define FORCSHARPCALC_API __declspec(dllimport)
#endif

#include "LibCalcDefine.h"

extern "C" FORCSHARPCALC_API int Add(int a, int b)
{
	Calculator cal;
	return cal.Add(a, b);
}

extern "C" FORCSHARPCALC_API int Substract(int a, int b)
{
	Calculator cal;
	return cal.Substract(a, b);
}


extern "C" FORCSHARPCALC_API int Multiply(int a, int b)
{
	Calculator cal;
	return cal.Multiply(a, b);
}
