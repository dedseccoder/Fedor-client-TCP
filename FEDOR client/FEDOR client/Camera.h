#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

class CameraCV
{
public:
	void Camera_Connet(int port_input, std::string Name)
	{
		port = port_input;
		std::cout << "starting camera... " << std::endl;
		VideoCapture cam;// open the camera
		cam.open(0, CAP_DSHOW);
		cv::Mat frame;
		while (waitKey(1) != ']')
		{
			cam >> frame;
			imshow(Name, frame);
		}
	}
private:
	int port;
};