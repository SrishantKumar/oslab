#include <stdio.h>
#include <string.h>

int excel(const char *user_str) {
    char buf[128];

    if (!user_str)
        return -1;

    strncpy(buf, user_str, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    printf("excel(): %s\n", buf);

    return 0;
}

int main() {
    excel("Hello from user space!");
    return 0;
}
