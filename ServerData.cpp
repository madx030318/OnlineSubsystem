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

  

  cout << "The Winsock is initialized" << endl;

  sockaddr_in ServerAddress;
  ServerAddress.sin_family = AF_INET;
  ServerAddress.sin_port = htons(NumberofPort);
  ServerAddress.sin_addr.s_addr = INADDR_ANY;

  bIsRunning = true;

  
}

void GameServer::Stop()
{
    Running = false;
    ServerSocket = 0;

    std::cout << "Game Server stopped." << std::endl;
}

void GameServer::AcceptClient()
{
    std::cout << "Waiting for client..." << std::endl;
}

void GameServer::HandleClient()
{
    std::cout << "Handling client..." << std::endl;
}

void GameServer::BroadcastMessage()
{
    std::cout << "Broadcasting message..." << std::endl;
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
