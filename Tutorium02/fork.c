#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void) {
    pid_t pid, pid2;
    switch(pid = fork()) {
        case -1:
            perror("fork failed");
            break;
        case 0:
            printf("I am the child process: pid=%d\n", getpid());
            break;
        default: // pid > 0
            printf("I am the parent process: child pid=%d\n", pid);
            wait(NULL);
            printf("Child process finished.\n");
            break;
    }


    return 0;
}
