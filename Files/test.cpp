#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>

using namespace cv; //tells what library to look in
using namespace std;


void main() {

	string path = "Resources/test.jpg";

	Mat img = imread(path);
	imshow("Image", img);
	waitKey(0);


}