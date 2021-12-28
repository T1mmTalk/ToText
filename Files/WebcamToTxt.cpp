#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
//#include <fstream>
#include <string>
#include "ToTxt.h"

using namespace cv;
using namespace std;



void main() {

	//string path = "Resources/BadApple.mp4";
	VideoCapture cap(0);
	//Mat blur, canny;
	int Sy = 63;
	int Sx = 200;
	//int s = 0;
	Mat img, blur, canny, dil, re;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));//increasing the size means it dialates more (only use odd numbers)

	while (true) {

		cap.read(img);

		GaussianBlur(img, blur, Size(7, 7), 5, 0);

		Canny(blur, canny, 50, 40);


		dilate(canny, dil, kernel);// increases line thickness

		resize(dil, re, Size(Sx, Sy), 0, 0, 1);

		cout << VidTxt(re, Sx, Sy);


	}

}