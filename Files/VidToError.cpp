#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <fstream>
//#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <thread>
#include "ToTxt.h"
using namespace cv;
using namespace std;



void thing(Mat re, int Sx, int Sy) {

	string frame = VidTxt(re, Sx, Sy);
	typedef const wchar_t* LPCWSTR;
	wstring stemp = s2ws(frame);
	LPCWSTR c = stemp.c_str();

	MessageBox(0, c, L"ERROR", MB_OK);
	
}

void main() {

	string path = "Resources/BadApple.mp4";
	VideoCapture cap(path);
	Mat img, re;
	int Sy = 63;
	int Sx = 200;
    LPCWSTR b = L"ERROR";

	while (true) {

		cap.read(img);
		resize(img, re, Size(Sx, Sy), 0, 0, INTER_LINEAR);
		
		
		thread first(thing, re, Sx, Sy);

		ExtKey();
		first.join();
		
			
			
		
		
			
	}
}

