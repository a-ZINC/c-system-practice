#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main() {
    printf("hello world \n");
    int a = 10;
    pid_t cid = fork();

    if (cid == 0) {
        a = 20;
        printf("child %d\n", a);
    } else {
        sleep(5);
        printf("parent %d\n", a);
    }

    return 0;
}