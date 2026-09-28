#pragma once
#include <iostream>
#include <string>
#include <winsock2.h>

class GameClient {
private:
SOCKET ClientSocket;
string ServerIp;
int ServerPort;

public:
GameClient();
bool Connect();
void SendMessageToServer(const std::string& Message);
void ReceiveMessage();
void Disconnect();


};
