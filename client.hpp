//
//  client.hpp
//  client1
//
//  Created by programer on 2023/7/24.
//

#ifndef client_hpp
#define client_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Client
{
public:
    Client(const string &ipAddress,int port);
    ~Client();
    
    void Connect();
    void Chat();
    void ReciveChat();
    
private:
    string ipAddress;
    int port;
    int clientSocket;
};
#endif /* client_hpp */
