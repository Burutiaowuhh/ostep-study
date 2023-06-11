#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{

    printf("开始fork\n");
    int rc = fork();
    
    FILE *fp = fopen("./h2.txt", "a+");
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
        fprintf(fp, "name:%s\n", "mao");
        fprintf(fp, "age:%d\n", 20);
        printf("子进程中count数字：%d\n", count);

    } else {
        // 父进程
        printf("父进程\n");
        count = 101;
        // wait(NULL);
        fprintf(fp, "name:%s\n", "hhh");
        fprintf(fp, "age:%d\n", 280);
        printf("父进程中count数字：%d\n", count);
        printf("父进程中count数字：%d\n", count);
    }
    
    fclose(fp);
    
    return 0;
}
