#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{

    printf("开始fork\n");
    int rc = fork();
    
    int count = 100;

    if (rc < 0)
    {
        /* code */
        fprintf(stderr, "创建子进程失败\n");
        exit(1);
    } else if (rc == 0)
    {
        /* code */
        // 开始子进程
        printf("子进程创建完毕\n");
        count = 102;
        printf("子进程中count数字：%d\n", count);

    } else {
        // 父进程
        printf("父进程\n");
        count = 101;
        wait(NULL);
        printf("父进程中count数字：%d\n", count);
        printf("父进程中count数字：%d\n", count);
    }
    
    
    
    return 0;
}
