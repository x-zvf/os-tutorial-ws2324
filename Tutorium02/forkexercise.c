#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;
    switch( (pid = fork()) )
    {
        case -1:
            printf( "Error. Fork failed\n" );
            break;
        case 0:
            printf( "I am the child!\n" );
            break;
        default: // pid > 0
            printf( "I am the parent!\n" \
                    "Child PID is %d\n", pid );
            wait( NULL );
            printf( "Child terminated\n" );
    }
}
