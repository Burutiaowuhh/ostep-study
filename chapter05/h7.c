#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{

    printf("开始fork\n");
    int pipefd[2];
    // pipe用于创建管道，它会返回大小为2的文件描述符数组，fd[0]代表管道读端，fd[1]代表管道写端
    pipe(pipefd);  

    int pid1 = fork();

    if (pid1 == 0)
    {
        /* code */
        // 关闭管道的读端
        close(pipefd[0]);
        // 将此子进程的标准输出重定向到管道的写端
        dup2(pipefd[1], STDOUT_FILENO);
        execlp("ps", "ps", "-ef", NULL);
    }

    int pid2 = fork();
    if (pid2 == 0)
    {
        /* code */
        // 关闭管道的写端
        close(pipefd[1]);
        // 将此子进程的标准输入重定向到管道的读端
        dup2(pipefd[0], STDIN_FILENO);
        execlp("wc", "wc","-l",  NULL);
    }
    
    // 关闭管道
    close(pipefd[0]);
    close(pipefd[1]);

    wait(NULL);
    wait(NULL);
    
    return 0;
}
