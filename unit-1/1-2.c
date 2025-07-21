#include <fcntl.h>   //File Control Operations
#include <unistd.h>  //POSIX API --  read(), write(), and close() 

int main() {

int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0644);  //rw-r-r
char buffer[1024];

int n;

while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
write(fd2, buffer, n);

close(fd1);
close(fd2);
return 0;

}

