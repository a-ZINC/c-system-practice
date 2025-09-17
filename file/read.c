#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main() {
    int fd = open("bro.txt", O_RDWR | O_APPEND | O_CREAT, 0644);
    if (fd < 0) {
        write(1, "bruh error opening", 15);
        perror("Open");
    }

    char *str = "bruh\n";
    int size = write(fd, str, 5);
    if (size < 0) {
        perror("Write");
    }
    printf("wrote %d bytes\n", size);

    lseek(fd, 0, SEEK_SET);

    char buffer[20];
    size = read(fd, buffer, 5);
    switch (size) {
        case 0:
            printf("end of file reached\n");
            break;
        case -1:
            perror("Read");
            break;
        default:
            printf("read %d bytes: %.*s\n", size, size, buffer);
            break;
    }

    int result = close(fd);
    if (result < 0) {
        perror("Close");
    }
    return 0;
}