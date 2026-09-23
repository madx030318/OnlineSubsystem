#include <iostream>
#include "ServerData.h"
#include <string>
#include <vector>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")

GameServer::GameServer() {
  ServerSocket = INVALID_SOCKET;
  Running = false;
  NumberofPort = 8000;


void GameServer::Start()
{
  WSADATA WsaD;
  int Output = WSAStatup(MAKEWORD(2, 2), &WSaData);

  if (Output != 0) {
    cout << "WSAStartup failed." << std::endl;
    return;

  }

  ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if  (ServerSocket == INVALID_SOCKET) {

     cout << "Socket creation failed." << endl;

     WSACleanup();
     return;

  }

  cout << "Server bound to port " << NumberofPort << endl;

  if (listen(ServerSocket, SOMAXCONN) == SOCKET_ERROR))
  {
    cout << "Listen failed." << endl;

    closesocket(ServerSocket);
    ServerSocket = INVALID_SOCKET;

    WSACleanup();

    return;

  }

  cout << "Server is listening." << endl;
  bIsRunning = true;
  cout << "The Winsock is initialized" << endl;

  sockaddr_in ServerAddress;
  ServerAddress.sin_family = AF_INET;
  ServerAddress.sin_port = htons(NumberofPort);
  ServerAddress.sin_addr.s_addr = INADDR_ANY;

  bIsRunning = true;

  
}

void GameServer::Stop()
{
  if (ServerSocket != INVALID_SOCKET) {

    closesocket(ServerSocket);
    ServerSocket = INVALID_SOCKET;

  }

  WSACleanup();

  bIsRunning = false;

  cout << "Game Server stopped. " << endl;
}
    

SOCKET GameServer::AcceptClient()
{
  sockaddr_in ClientAddress;
  int ClientAddressSize = sizeof(ClientAddress);
  SOCKET ClientSocket = accept(ServerSocket, reinterpret_cast<sockaddr*>(&ClientAddress), &ClientAddressSize);

  if (ClientSocket == INVALID_SOCKET)
  {
    cout << "Accept failed." << std::endl;
    return INVALID_SOCKET;

    cout << "Client connected!" << std::endl;

    return ClientSocket;

  }
}

void GameServer::HandleClient()
{
    char Buffer[1024];

    int BytesReceived = recv(
        ClientSocket,
        Buffer,
        sizeof(Buffer) - 1,
        0 );
}

void GameServer::BroadcastMessage()
{
    cout << "Broadcasting message..." << endl;
}


}

int main() {

  GameServer Server;
  Server.Start();

  Server.AcceptClient();
  Server.HandleClient();
  Server.BroadcastMessage();

  Server.Stop();

  return 0;



}
