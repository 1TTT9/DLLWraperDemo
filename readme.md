#  DLL Helloworld

This project demonstrates two things:
  - how c# program calls C++ functions by DLL
  - how a c++/c# native class wrapper is implemented
 
# Environment
- Windows 10 
- Visual Studio 2017
- WPF 

# Folders
**root**
	+	**cpp/\***
&nbsp;	/ ** **_workthrough example from MSDN_** ** /
	+	**cpp2/**
&nbsp;	|	+ **CSGPPainter.cpp**
&nbsp;	|	+ **libGUIPainterDefine.h**
&nbsp;	|	+ **libGUIPainterImpl.cpp**
	+  **cs/** 
&nbsp;	/** **_csharp implementation_** **/
&nbsp;	| + **MainHelloWorld.cs**
&nbsp;	| + **MainHelloWorld.xaml.cs**

# Workflow
1. Create a DLL Project on VS2017
2. turn on CLR 
3. define public function calls on **CSGPPainter.cpp**
4. define class/member variables/member functions through header **libGUIPainterDefine.h**
5. implement all consumption logics on **libGUIPainterImpl.cpp** referred to its header
6. **notice**: 
	 - need to handle unmanaged data carefully
	 - how to manipulate array (double/int/byte) operation, either work as arguments or returned values does the tricks
	 - DLL better to recreate and compile when it's taken used on VS2015 project. Also, In VS2015, it's entirely different to create a new C++ DLL project
	 - Rest of the work needs good luck... 

