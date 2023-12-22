#include<sys/wait.h>
#include<unistd.h>

#define READ_END 0
#define WRITE_END 1

int main(void) {
    int pid, pipefd[2];
    pipe(pipefd);

    if((pid = fork()) == 0) {
        dup2(pipefd[WRITE_END], STDOUT_FILENO);
        close(pipefd[READ_END]);
        close(pipefd[WRITE_END]);
        execlp("ls", "ls", NULL);
    }
    else {
        if((pid = fork()) == 0) {
            dup2(pipefd[READ_END], STDIN_FILENO);
            close(pipefd[READ_END]);
            close(pipefd[WRITE_END]);
            execlp("less", "less", NULL);
        }
        else {
            close(pipefd[READ_END]);
            close(pipefd[WRITE_END]);
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}
