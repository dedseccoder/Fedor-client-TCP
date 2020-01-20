//everything still in progress, so if you want working version, douwnload the one befor this



#pragma comment (lib, "ws2_32.lib")
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <winsock2.h>
#include <iostream>

#pragma warning (disable: 4996);

using namespace std;

SOCKET operator_socket;

//void GetMSG()
//{
//	char msg[256];
//	while (true)
//	{
//		recv(operator_socket, msg, size(msg), NULL);
//		cout << msg << endl;
//	}
//}

int main()
{
	system("color a");
	// choose lib version
	WSAData wsaData;
	WORD lib_version = MAKEWORD(2, 1);
	//lib installation check 
	if (WSAStartup(lib_version, &wsaData) != 0)
	{
		cout << "WSAStartup ERROR" << endl;
		system("pause");
		exit(1);
	}
	// Enter user's IP for not only one machine
	char IP [20];
	cout << "input your local IP address ";
	cin >> IP;
	// SOCKADDR_IN gets user's IP address
	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = inet_addr(IP);
	cout << "Robot: 10099" << endl;
	cout << "Moon Rover: 11099" << endl;
	cout << "eye 1: 800" << endl;
	cout << "eye 2: 801" << endl;
	cout << "Ray cloud: 2368" << endl;
	cout << "Scene (for reset): 1000" << endl;
	cout << "enter port: ";
	int port;
	cin >> port;
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	//creat socket for connetion to server
	SOCKET operator_socket = socket(AF_INET, SOCK_STREAM, NULL);
	//connection to server with check
	if (connect(operator_socket, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout << "Connection ERROR" << endl;
		system("pause");
		return 1;
	}
	cout << "Connection succeeded" << endl;

	if (port == 801 || port == 800)
	{
		cv::VideoCapture cam;// open the camera
		cam.open(0, cv::CAP_DSHOW);
		cv::Mat frame;
		while (cv::waitKey(1) != 'a')
		{
			cam >> frame;
			imshow("test", frame);
		}
	}

	//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) GetMSG, NULL, NULL, NULL);

	char buffer[256];
	char msg[256];
	while (true)
	{
		recv(operator_socket, msg, size(msg), NULL);
		cout << msg << endl;
		cin.getline(buffer, size (buffer));
		send(operator_socket,buffer, size (buffer), NULL);
		Sleep(4);
		if (buffer == "stop")
		{
			break;
		}

	}
	system("pause");
	return 0;
}