#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAXLINE 100

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if ((pid = fork()) < 0) {
            err_sys("fork error!");
        } else if (0 == pid) {
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if (pid = waitpid(pid, &status, 0) < 0)
            err_sys("waitpid error!");

        printf("%% ");
    }
    exit(0);
}
  
12  3.1.c
@@ -0,0 +1,12 @@
#include <stdio.h>
#include <unistd.h>

int main()
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("Cannot seek\n");
    else
        printf("seek OK\n");

    return 0;
}
  
45  3.2.c
@@ -0,0 +1,45 @@
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define  FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

#define err_sys(info)                                            \
{                                                                \
    printf("%s\n", (info));                                       \
    exit(-1);                                                    \
}

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
    int fd;

    if ((fd = open("file.nohole", O_WRONLY)) < 0) {
        printf("Open Error\n");
    }

    if ((fd = creat("file.nohole", FILE_MODE)) < 0) {
        err_sys("Create Error\n");
    }

    if (write(fd, buf1, 10) != 10) {
        err_sys("buf1 write error\n");
    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("lseek error\n");
    }

    if (write(fd, buf2, 10) != 10) {
        err_sys("buf2 write error\n");
    }

    if (close(fd) < 0) {
        err_sys("Close Error\n");
    }

    return 0;
}
  
30  3.3.c
@@ -0,0 +1,30 @@
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFSIZE    4096

#define err_sys(info)                                            \
{                                                                \
    printf("%s\n", (info));                                       \
    exit(-1);                                                    \
}

int main()
{
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }

    if (n < 0) {
        err_sys("Read Error");
    }

    return 0;
}