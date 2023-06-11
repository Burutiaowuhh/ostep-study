#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    /* code */
    printf("hello world(pid:%d)\n", (int)getpid());
    int rc = fork();
    // printf("rc:%d\n", rc);
    if (rc < 0) // fork failed
    {
        /* code */
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) // child (new process)
    {
        /* code */
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    }
    else
    { // parent goes down this path(main)
    int wc = wait(NULL);
        printf("hello, I am parent of %d(wc:%d)(pid%d)\n", rc, wc, (int)getpid());
    }

    return 0;
}
