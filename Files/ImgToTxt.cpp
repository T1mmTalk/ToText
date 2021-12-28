#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include "ToTxt.h"

using namespace std;
using namespace cv;



void main() {


	string path = "Resources/Capture.PNG";
	int y = 200;
	int x = 200;
	cout << imgTxt(path, x, y);
}

