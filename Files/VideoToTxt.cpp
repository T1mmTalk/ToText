#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "ToTxt.h"

using namespace cv;
using namespace std;



void main() {

	string path = "Resources/BadApple.mp4";
	VideoCapture cap(path);
	
	int Sy = 63;
	int Sx = 200;
	//int s = 0;
	Mat img, re;
	

	while (true) {
		
		cap.read(img);
		resize(img, re, Size(Sx, Sy), 0, 0, 1);
		cout << VidTxt(re, Sx, Sy);
		waitKey(1);
		
	}

}