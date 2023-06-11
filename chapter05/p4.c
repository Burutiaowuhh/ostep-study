#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    /* code */
    // printf("hello world(pid:%d)\n", (int)getpid());
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
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        char *myargs[4];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p4.c");
        myargs[2] = strdup("-l");
        myargs[3] = NULL;
        execvp(myargs[0], myargs);
        printf("this shouldn't print out\n");
    }
    else
    { // parent goes down this path(main)
        int wc = wait(NULL);
        // printf("hello, I am parent of %d(wc:%d)(pid%d)\n", rc, wc, (int)getpid());
    }

    return 0;
}
