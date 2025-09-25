#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    char *big_arry = malloc(1024 * 1024 * 1024);
    if (big_arry == NULL) {
        printf("failed to allocate");
        return -1;
    }

    printf("press enter to see page fault");
    getchar();

    for (int i=0; i< 1024 * 1024; i++){
        big_arry[i * 1024] = 'A';
    }

    printf("accessed page");
    sleep(10);
    free(big_arry);
    return 0;
}