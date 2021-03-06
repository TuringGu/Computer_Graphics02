// HDRTest02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

#define WAITKEY_DELAY 30
#define CAMERA_DEVICE 0

int main(void)
{
	VideoCapture captureDevice(CAMERA_DEVICE);
	if (!captureDevice.isOpened())
		return -1;

	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		captureDevice >> frame;
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		imshow("edges", edges);
		auto key = waitKey(WAITKEY_DELAY);
		if (key >= 0)
			break;
	}
}
