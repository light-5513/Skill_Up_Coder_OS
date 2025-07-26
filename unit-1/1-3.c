#include <stdio.h>      // For printf and perror
#include <unistd.h>     // For fork, execl, getpid, getppid
#include <stdlib.h>     // For exit
#include <sys/types.h>  // For pid_t type (process ID)
#include <sys/wait.h>   // For wait and macros to check child status

int main() {

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;  // return with error
    }

    if (pid == 0) {
        // Child process
        printf("Child: My PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Child: Executing 'ls -l'\n");

        // exec() replaces the child process image with /bin/ls
        execl("/bin/ls", "ls", "-l", NULL);

        // If exec fails
        perror("exec failed");
        exit(1); // exit with error
    } else {
        // Parent process
        printf("Parent: My PID = %d, Child PID = %d\n", getpid(), pid);

        Wait for the child to finish
        wait(NULL);

        // Exit parent cleanly
        exit(0);
    }
}
