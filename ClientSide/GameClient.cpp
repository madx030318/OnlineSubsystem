#include "GameClient.h"

#pragma comment(lib, "Ws2_32.lib")

GameClient::GameClient()
{
    ClientSocket = INVALID_SOCKET;

    ServerIP = "127.0.0.1";
    ServerPort = 54000;
}
