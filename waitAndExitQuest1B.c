#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int rv;

    switch (pid = fork()) {
        case -1:
            perror("fork");
            exit(1);

        case 0:  
            printf("\nCHILD: This is the child process!\n");
            fflush(stdout);

            printf("\nCHILD: My PID is %d\n", getpid());
            printf("\nCHILD: My parent's PID is %d\n", getppid());

            printf("\nCHILD: Enter my exit status (make it small): ");
            scanf("%d", &rv);

            printf("\nCHILD: I'm outta here!\n");
            exit(rv);

        default: 
            printf("\nPARENT: This is the parent process!\n");
            printf("\nPARENT: My PID is %d\n", getpid());
            fflush(stdout);

            wait(&rv); 
            fflush(stdout);

            printf("\nPARENT: My child's PID is %d\n", pid);
            printf("\nPARENT: I'm now waiting for my child to exit()...\n");
            fflush(stdout);

            printf("\nPARENT: My child's exit status is: %d\n", WEXITSTATUS(rv));
            printf("\nPARENT: I'm outta here!\n");
    }
    return 0;
}
