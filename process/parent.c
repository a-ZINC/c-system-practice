#include <stdio.h>
#include <unistd.h>


// swapper process(kernel space process) (pid = 0) first process which create init process
//      -> its kernal process which hardcoded into kernel during bootload
//      -> when set to kernel memory create init process or systemd (first user space process)
//      -> if no other process is executing it give samll tak to cpu to keep it busy. so that it doesnt crash (running into garbage memeory)
// init process(first user space process) (pid = 0) parent of all orphan process
//      
int main() {
    printf("My parent process ID is %d\n", getppid());
    printf("My process ID is %d\n", getpid());
}