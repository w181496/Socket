#include<winsock2.h>
#include<stdio.h>
#include<iostream>
#include<string>
#pragma comment (lib, "Ws2_32.lib")
using namespace std;
int main()
{
    char str[500];  //user input
    cin>>str;
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2),&wsaData);

    SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in sockaddr;
    sockaddr.sin_family = PF_INET;
    sockaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //ip
    sockaddr.sin_port = htons(827);

    bind(s, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));

    listen(s, 1);

    SOCKADDR clientAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET clientSock;
    clientSock = accept(s, (SOCKADDR*)&clientAddr, &nSize);

    send(clientSock,str,strlen(str) + sizeof(char), NULL);

    closesocket(clientSock);
    closesocket(s);

    WSACleanup();
    return 0;
}
