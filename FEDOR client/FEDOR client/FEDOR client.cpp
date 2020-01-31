//everything still in progress, so if you want working version, douwnload the one befor this



#pragma comment (lib, "ws2_32.lib")
#include <winsock2.h>
#include "Camera.h"
#include <iostream>

#pragma warning (disable: 4996);

using namespace std;

int main()
{
	system("color a");
	// choose lib version
	WSAData wsaData;
	WORD lib_version = MAKEWORD(2, 2);
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

	if (port == 800 || port == 801)
	{
		CameraCV get;
		get.Camera_Connet(port, "Fedor Camera");
	}

	char buffer[256];
	char msg[256];
	int SIZE;
	while (true)
	{
		cin.getline(buffer, size (buffer));
		send(operator_socket,buffer, sizeof(buffer), NULL);
		SIZE = recv(operator_socket, msg, size(msg), NULL);
		cout << "SIZE = " << SIZE << endl;
		cout << hex << msg << endl;
		Sleep(2);
		if (buffer == "stop")
		{
			break;
		}

	}
	system("pause");
	return 0;
}