#pragma once
#include <iostream>
#include <string>

class GameServer
{
private:
    int ServerSocket;
    bool Running;

public:
    void Start();
    void Stop();

    void AcceptClient();
    void HandleClient();

    void BroadcastMessage();
};
