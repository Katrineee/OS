#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    printf("SIGINT signal caught!\n");
    exit(0);
}

int main() {
    signal(SIGINT, signal_handler);
    printf("Press Ctrl+C to generate SIGINT...\n");
    while (1);
    return 0;
}
