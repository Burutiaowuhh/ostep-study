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
        /* code */
        // 开始子进程

        int w = waitpid(NULL);
        printf("wait:%d\n", w);
        printf("hello  %d\n", (int)getpid());

        execl("/bin/ls", "ls", NULL);

    } else {
        // 父进程
        int w = waitpid(NULL);
        printf("wait:%d\n", w);
        printf("goodbye\n");
    }
    
    printf("pid:%d 结束\n", (int)getpid());
    
    return 0;
}
