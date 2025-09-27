#include<stdio.h>
#include<unistd.h>

int main() {
    long page_size = sysconf(_SC_PAGESIZE);
    printf("bruh page size %ld \n", page_size/1024);
    return 0;
}