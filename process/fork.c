#include<stdio.h>
#include<unistd.h>
#include<time.h>


int main() {
    printf("hello world \n");
    pid_t cid = fork();

    if (cid == 0) {
        printf("child \n");
    } else {
        sleep(5);
        printf("parent \n");
    }

    return 0;
}