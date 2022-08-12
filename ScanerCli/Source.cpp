#include <winsock2.h>
#include <iostream>
#include <string>;
#pragma comment (lib, "ws2_32.lib")

#pragma warning (disable: 4996)

using namespace std;

SOCKADDR_IN addr; 
SOCKET Connection;

void wsa()
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		cout << "Error" << endl;
		exit(1);
	}
}

void settingUp_addr(char IP[256], int port)
{
	int sizeoffaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr(IP);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
}

bool connect()
{
	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout << "Error of connection";
		return 0;
	}
	else
	{
		cout << "Connected" << endl;
		
		return 1;
	}

}

int main(int argc, char* argv[])
{
	char msg[256];
	char IP[256] = " ";
	short port(0);

	wsa();

	t0:
	cout << "IP: " << endl;
	cin >> IP;
	cout << "Port: " << endl;
	cin >> port;
	system("cls");
	settingUp_addr(IP, port);
	if (connect() == 0) 
	{
		system("cls");
		goto t0;
	}
	else 
	{
		f:
		recv(Connection, msg, sizeof(msg), NULL);
		cout << msg << endl;
		goto f;

	}
	return 0;
}
