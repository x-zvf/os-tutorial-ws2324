#include<unistd.h>
#include<sys/wait.h>

#define READ_END 0
#define WRITE_END 1

int main(void) {
    int pid;
    int fd[2];
    pipe(fd);

    if((pid = fork()) == 0) {
        dup2(fd[WRITE_END], STDOUT_FILENO);
        close(fd[READ_END]);
        close(fd[WRITE_END]);
        execlp("ls", "ls", NULL);
    } else {
        if((pid = fork()) == 0) {
            dup2(fd[READ_END], STDIN_FILENO);
            close(fd[READ_END]);
            close(fd[WRITE_END]);
            execlp("less", "less", NULL);
        } else {
            close(fd[READ_END]);
            close(fd[WRITE_END]);
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}
