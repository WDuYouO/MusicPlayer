#include <winsock2.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib") 

class ServerSocket{
public:
    ServerSocket(){
        m_bInit = false;
        m_ListenSocket = -1;
    }
    ~ServerSocket(){
        if(m_ListenSocket != -1)
            ::closesocket(m_ListenSocket);
        if(m_bInit)
            ::WSACleanup();
    }
    bool DoInit(){
        //初始化socket库
        WORD wVersionRequested = MAKEWORD(2,2);
        WSADATA wsaDATA;
        int err = ::WSAStartup(wVersionRequested,&wsaDATA);
        if(err != 0)
            return false;
        if(LOBYTE(wsaDATA.wVersion) != 2 || HIBYTE(wsaDATA.wVersion) != 2)
            return false;
        m_bInit = true;

        //创建用于监听的socket
        m_ListenSocket = ::socket(AF_INET, SOCK_STREAM, 0);
        if(m_ListenSocket == -1)
            return false;
        std::cout<<"Init----------------------";
        return true;

    }

    bool DoBind(const char* ip,short port = 6000){
        SOCKADDR_IN addrSrv;
        addrSrv.sin_addr.S_un.S_addr = inet_addr(ip);
        addrSrv.sin_family = AF_INET;
        addrSrv.sin_port = htons(port);
        if(::bind(m_ListenSocket, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == -1)
            return false;
        return true;
    }

    bool DoListen(int backlog = 15){
        if(::listen(m_ListenSocket, backlog) == -1)
            return false;
        return true;
    }

    bool DoAccept(){
        SOCKADDR_IN addrClient;
        int len = sizeof(SOCKADDR);
        char msg[] = "Hello World";
        while(true){
            //等待客户端的请求，有则连接
            SOCKET sockClient = ::accept(m_ListenSocket, (SOCKADDR*)&addrClient, &len);
            if(sockClient == -1)
                break;
            //向客户端发送消息
            ::send(sockClient, msg, strlen(msg), 0);
            ::closesocket(sockClient);
        }
        return false;
    }
private:
    bool m_bInit;
    bool m_ListenSocket;
};

int main(int argc,char* argv[]){
    ServerSocket serverSocket;
    if(!serverSocket.DoInit())
        return false;
    if(!serverSocket.DoBind("127.0.0.1",6000))
        return false;
    if(!serverSocket.DoListen(15))
        return false;
    if(!serverSocket.DoAccept())
        return false;
    return 0;
}