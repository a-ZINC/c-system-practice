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
        sleep(1);
        pid_t cid2 = fork();
        if (cid2 == 0) {
            sleep(30);
            printf("sub-child %d\n", a);
        } else {
            printf("parent %d\n", a);
        }
    }

    return 0;
}