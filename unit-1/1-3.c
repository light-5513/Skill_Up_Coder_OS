#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

pid_t pid = fork();

if (pid < 0) {
perror("fork failed");
return 1;
}

if (pid == 0) {
// Child process
printf("Child: My PID = %d, Parent PID = %d\n", getpid(), getppid());
printf("Child: Executing 'ls -l'\n");                              
                                                                
// exec() replaces the child process image with /bin/ls                                        
execl("/bin/ls", "ls", "-l", NULL);                                                             
                                                
// If exec fails
perror("exec failed");                                                            
exit(1);

} else {
// Parent process
printf("Parent: My PID = %d, Child PID = %d\n", getpid(), pid);

int status;
wait(&status); // Wait for child to finish

if (WIFEXITED(status)) {
printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
} else {
printf("Parent: Child did not exit normally\n");
}
}

return 0;
}
