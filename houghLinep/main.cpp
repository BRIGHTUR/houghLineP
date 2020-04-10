#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcMat = imread("test.png");
	Mat cannyMat;
	Mat dstMat;
	cvtColor(srcMat, dstMat, CV_BGR2GRAY);
	Canny(dstMat, cannyMat, 100, 170, 3);
	vector<cv::Vec4i> lines;
	HoughLinesP(cannyMat, lines, 1, CV_PI / 180, 47, 10, 20);
	for (size_t i=0; i < lines.size(); i++) {
		Point pt1, pt2;
		pt1.x = lines[i][0];
		pt1.y = lines[i][1];
		pt2.x = lines[i][2];
		pt2.y = lines[i][3];
		line(srcMat,	pt1, pt2, cv::Scalar(0, 255, 255), 2, CV_AA);
	}
	imshow("dst", cannyMat);
	imshow("src", srcMat);
	waitKey(0);
}