#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{

    printf("开始fork\n");
    int rc = fork();

    if (rc < 0)
    {
        /* code */
        fprintf(stderr, "创建子进程失败\n");
        exit(1);
    } else if (rc == 0)
    {
        // 开始子进程
        // 关闭标准输出
        close(STDOUT_FILENO);

        printf("这是子进程\n");

    } else {
        // 父进程
        printf("goodbye\n");
    }
    return 0;
}
