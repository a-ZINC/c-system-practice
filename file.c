#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main() {
    int fd = open("test.txt", O_RDONLY | O_CREAT, 0644);
    if (fd == -1) {
        char errorMsg[50];
        snprintf(errorMsg, sizeof(errorMsg), "Error opening file %d\n", errno);
        write(1, errorMsg, strlen(errorMsg));
        perror("Error printed by perror");
    } else {
        char doneMsg[50];
        snprintf(doneMsg, sizeof(doneMsg), "File opened successfully with fd: %d\n", fd);
        write(1, doneMsg, strlen(doneMsg));
        close(fd);
    }
    return 0;
}