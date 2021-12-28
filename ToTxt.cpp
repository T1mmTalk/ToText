
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <Windows.h>

#include "ToTxt.h"


using namespace std;
using namespace cv;

string imgTxt(string path, int Sx, int Sy) {

	Mat img = imread(path);
	Mat  re;
	//Mat blur, canny;


	//GaussianBlur(img, blur, Size(7, 7), 5, 0);

	//Canny(blur, canny, 25, 25);

	resize(img, re, Size(Sx, Sy), 0, 0, 1);
	string frame;

	for (int y = 0; y < Sy; y++) {
		for (int x = 0; x < Sx; x++) {
			unsigned char* p = re.ptr(y, x);
			if (p[0] < 200) {
				char cch = 'a' +rand() % 26;
				frame += cch;
			}
			else {
				frame += " ";
			}
		}
		frame += '\n';
	}

	return frame;

}

string imgTxt2(string path, int Sx, int Sy) {

	Mat img = imread(path);
	Mat  re;
	//Mat blur, canny;


	//GaussianBlur(img, blur, Size(7, 7), 5, 0);

	//Canny(blur, canny, 25, 25);

	resize(img, re, Size(Sx, Sy), 0, 0, 1);
	string frame;

	for (int y = 0; y < Sy; y++) {
		for (int x = 0; x < Sx; x++) {
			unsigned char* p = re.ptr(y, x);
			if (p[0] < 200) {
				char cch = 'a' + rand() % 26;
				frame += cch;
			}
			else {
				frame += "  ";
			}
		}
		frame += '\n';
	}

	return frame;

}

string CannyTxt(string path, int Sx, int Sy) {
	Mat img = imread(path);
	Mat re, blur, canny, dil;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

	GaussianBlur(img, blur, Size(7, 7), 5, 0);

	Canny(blur, canny, 25, 25);
	dilate(canny, dil, kernel);
	resize(canny, re, Size(Sy, Sx), 0, 0, 1);
	string frame;

	for (int y = 0; y < Sy; y++) {
		for (int x = 0; x < Sx; x++) {
			unsigned char* p = re.ptr(y, x);
			if (p[0] < 200) {
				char cch = 'a' + rand() % 26;
				frame += cch;
			}
			else {
				frame += " ";
			}
		}
		frame += '\n';
	}

	return frame;

}

String VidTxt(Mat re,int Sx, int Sy) {
	


	

	//ofstream myfile;
	//myfile.open(path2 + name + ".txt");

	string frame;

	for (int y = 0; y < Sy; y++) {
		for (int x = 0; x < Sx; x++) {
			unsigned char* p = re.ptr(y, x);
			if (p[0] < 200) {
				char cch = 'a' + rand() % 150;
				frame += cch;
			}
			else {
				frame += " ";
			}

		}
		frame += '\n';
	}

	return frame;
}

wstring s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

void ExtKey() {

	Sleep(1000);
	INPUT ip;
	// ...
		// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	// Press the "A" key
	ip.ki.wVk = 0x1B; // virtual-key code for the "esc" key
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));
}
