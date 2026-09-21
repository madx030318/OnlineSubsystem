#pragma once
#include <iostream>
#include <string>
#include <winsock2.h>

class GameServer
{
private:
     
    SOCKET ServerSocket;
    bool Running;
    int NumberofPort

public:
    void Start();
    void Stop();

    void AcceptClient();
    void HandleClient();

    void BroadcastMessage();
};
