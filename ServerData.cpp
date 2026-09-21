#include <iostream>
#include "ServerData.h"
#include <string>
#include <vector>

GameServer::GameServer() {
  ServerSocket = 0;
  Running = false;

void GameServer::Start() {

  Running = true;
  
};

void GameServer::Start()
{
    Running = true;

    std::cout << "Game Server started." << std::endl;
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
