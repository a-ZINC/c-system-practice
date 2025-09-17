#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

int main() {
    printf("Hello bud \n");

    char *msg = "Syscall babe \n";
    write(1, msg, strlen(msg));


    clock_t start, end;
    start = clock();
    for(int i=0; i < 1000; i++) {
        printf("Hello user mode \n");
    }
    end = clock();
    double printfTime = (double)(end-start) / CLOCKS_PER_SEC;

    start = clock();
    for(int i=0; i < 1000; i++) {
        write(1, "Hello kern mode \n", 17);
    }
    end = clock();
    double writeTime = (double)(end-start) / CLOCKS_PER_SEC;

    printf("Time taken by printf: %f\n", printfTime);
    printf("Time taken by writef: %f\n", writeTime);
    return 0;
}