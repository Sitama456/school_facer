#include<unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <memory.h>
#define MAX_FD 1000

int main() {
    // 1. 创建一个套接字
    int fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    // 设置非阻塞
    fcntl(fd, F_SETFL, O_NONBLOCK | O_CLOEXEC);

    // 2. 绑定地址
    sockaddr_in addr;
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(88888);
    int ret = bind(fd, (sockaddr*)&addr, sizeof(addr));

    // 3. 监听
    listen(fd, 10);

    // 4. epoll等待
    // 创建epoll实例
    int epollfd = epoll_create(MAX_FD);
    struct epoll_event epollEvent;
    epollEvent.events = EPOLLIN;
    epollEvent.data.fd = fd;
    // 加入监听socket
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &epollEvent);
    // 接受活跃的事件
    struct epoll_event events[MAX_FD];
    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_FD, -1);
        if (nfds < 0) {
            return -1;
        }
        for (int i = 0; i < nfds; ++i) {
            // 处理事件
            if (events[i].data.fd == fd) {
                sockaddr_in addr_cli;
                int socket_cli = accept4(fd, (sockaddr*)&addr_cli, sizeof(addr_cli), O_NONBLOCK | O_CLOEXEC);

            } else {
                
            }
        }
    }
}

int main1() {
    // 1. 创建socket
    int sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 2. 连接服务器 或者别的客户端
    sockaddr_in toAddr;
    toAddr.sin_addr.s_addr = inet_addr("192.168.0.15");
    toAddr.sin_port = htons(8888);
    toAddr.sin_family = AF_INET;

    int ret = connect(sockfd, (sockaddr*)&toAddr, sizeof(toAddr));
    if (ret == -1) {
        return -1;
    }

    // 3. 发送消息
    char buffer[128] = {"hello"};
    write(sockfd, buffer, sizeof(buffer));
    
    // 4. 接受消息
    int nread = read(fd, buffer, sizeof(buffer));
    if (nread == -1) {

    }

    // 5. 关闭链接
    close(sockfd);

    int flag = fcntl(sockfd, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(sockfd, F_SETFL, flag);
}