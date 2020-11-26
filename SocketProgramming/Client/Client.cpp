// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <winsock.h>
#include <iostream>
#include <Windows.h>
#include <string.h>

#define BUFSIZE 64


using namespace std;



int main()
{
	char buffer[BUFSIZE];

	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
	{
		cout << "WSADATA Failed!" << endl;
		exit(1);
	}

	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0)
	{
		cout << "Socket Creation Failed!" << endl;
		exit(1);
	}

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // 127.0.0.1 localaddr
	serverAddress.sin_port = htons(8000);

	
	if (connect(sockfd, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
	{
		cout << "Connect Failed!" << endl;
		exit(0);
	}

	char msg[] = "Hello Echo!\n";
	int numberofByte = send(sockfd, msg, strlen(msg), 0);
	if (numberofByte < 0)
	{
		cout << "Send Failed!" << endl;
		exit(1);
	}



	closesocket(sockfd);

	WSACleanup();

	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
