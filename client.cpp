//
//  client.cpp
//  client1
//
//  Created by programer on 2023/7/24.
//

#include "client.hpp"
#include <iostream> 
#include <cstring> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h> 

using namespace std;

Client::Client(const string &ipAddress,int port):ipAddress(ipAddress),port(port)
{   
    
    clientSocket=socket(AF_INET, SOCK_STREAM, 0);
}

Client::~Client()
{
    close(clientSocket);
}


void Client::Connect()
{   //描述伺服器的IP和PORT
    sockaddr_in Info;
    Info.sin_family=AF_INET;
    Info.sin_port=htons(port);
    
    inet_pton(AF_INET, ipAddress.c_str(), &Info.sin_addr);
    
    //連線到伺服器
    int connectResult=connect(clientSocket,(struct sockaddr*)&Info,sizeof(Info));
    if(connectResult == -1)
    {
        fprintf(stderr,"無法連線至伺服器");
    }
}
//與伺服器進行訊息交換
void Client::Chat()
{
    char buf[4096];
    while(true)
    {
        
        memset(buf,0,4096);
        
        
        string userInput;
        cout << "輸入： ";
        getline(cin, userInput);
        
        if(userInput.size()>0) 
        {
            
            send(clientSocket, userInput.c_str(), userInput.size(), 0);
        }
        

    }
}

//接收伺服器回傳的訊息
void Client::ReciveChat()
{
    char buf[4096];
    while(true)
    {
        
        memset(buf,0,4096);
        
        int bytesRecv=recv(clientSocket,buf,4095,0);
        if(bytesRecv <=0)
        {
            printf("與伺服器的連線 已斷開");
            break;
        }
        cout << "收到訊息： " << buf <<endl;
    }
}
