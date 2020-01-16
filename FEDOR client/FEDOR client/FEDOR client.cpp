#pragma comment (lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning (disable: 4996);

using namespace std;

int main()
{
	// выбор верссии сокет библиотеки
	WSAData wsaData;
	WORD lib_version = MAKEWORD(2, 1);
	//проверка успешности инициализации библиотеки 
	if (WSAStartup(lib_version, &wsaData) != 0)
	{
		cout << "WSAStartup ERROR" << endl;
		exit(1);
	}
	// ¬вод айпи дл€ любого компа
	char IP [20];
	cout << "input your local IP adress" << endl;
	cin >> IP;
	// SOCKADDR_IN хранит айпи адресс пользовател€
	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = inet_addr(IP);
	addr.sin_port = htons(10099);
	addr.sin_family = AF_INET;
	//создание сокета дл€ коннекта с сервером
	SOCKET operator_socket = socket(AF_INET, SOCK_STREAM, NULL);
	//коннект к серверу с проверкой
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