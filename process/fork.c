#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int cnt = 0;

int main() {
    printf("hello world \n");
    int a = 10;
    pid_t cid = fork();

    if (cid == 0) {
        cnt++;
        a = 20;
        pid_t cid2 = fork();
        if (cid2 == 0) {
            cnt++;
            printf("child sub-child %d %d\n", cnt, getppid());
            sleep(30);
        } else {
            cnt++;
            printf("child %d %d %d\n", cnt, getppid(), getpid());
            sleep(30);
        }
    } else {
        pid_t cid2 = fork();
        if (cid2 == 0) {
            cnt++;
            printf("parent child %d %d\n", cnt, getppid());
            sleep(30);
        } else {
            cnt++;
            printf("parent %d %d\n", cnt, getpid());
            sleep(30);
        }
    }

    return 0;
}