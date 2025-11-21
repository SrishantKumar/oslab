#include <stdio.h>
#include <unistd.h>

int main() {
    printf("step before execl call");
    execl("/bin/ls", "ls", "-l", (char *)NULL);
    printf("step after execl call"); // This line won't execute if execl succeeds
    return 0;
}