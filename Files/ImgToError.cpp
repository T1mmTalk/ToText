#include <Windows.h>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <thread>
#include <iostream>
#include "ToTxt.h"

    
using namespace std;

void main() {

	string path = "Resources/Capture.PNG";
	int y = 50;
	int x = 100;
	string s = imgTxt2(path, x, y);
	typedef const wchar_t* LPCWSTR;
	wstring stemp = s2ws(s);
	LPCWSTR c = stemp.c_str();
	//cout << s;
	MessageBox(0, c, L"ERROR", MB_OK);
}