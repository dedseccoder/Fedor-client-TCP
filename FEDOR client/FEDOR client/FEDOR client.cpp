#pragma comment (lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning (disable: 4996);

using namespace std;

int main()
{
	// ����� ������� ����� ����������
	WSAData wsaData;
	WORD lib_version = MAKEWORD(2, 1);
	//�������� ���������� ������������� ���������� 
	if (WSAStartup(lib_version, &wsaData) != 0)
	{
		cout << "WSAStartup ERROR" << endl;
		exit(1);
	}
	// ���� ���� ��� ������ �����
	char IP [20];
	cout << "input your local IP adress" << endl;
	cin >> IP;
	// SOCKADDR_IN ������ ���� ������ ������������
	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = inet_addr(IP);
	addr.sin_port = htons(10099);
	addr.sin_family = AF_INET;
	//�������� ������ ��� �������� � ��������
	SOCKET operator_socket = socket(AF_INET, SOCK_STREAM, NULL);
	//������� � ������� � ���������
	if (connect(operator_socket, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout << "Connection ERROR" << endl;
		system("pause");
		return 1;
	}
	else
	{
		cout << "Connection succeeded" << endl;
	}
	system("pause");
	return 0;
}