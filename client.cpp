#include<winsock2.h>
#include<stdio.h>
#pragma comment (lib, "Ws2_32.lib")

int main()
{
    while(1)
    {
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

        sockaddr_in sockAddr;
        sockAddr.sin_family = PF_INET;
        sockAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(827);

        connect(s, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

        char szBuffer[MAXBYTE] = { 0 };

        recv(s, szBuffer, MAXBYTE, NULL);

        printf("szBuffer = %s \r\n",szBuffer);

        closesocket(s);

        WSACleanup();
        system("PAUSE");
    }
    return 0;
}
