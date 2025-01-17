#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int sigint_count = 0;

void custom_signal_handler(int signum) {
    sigint_count++;
    printf("Caught SIGINT (signal number: %d). Count: %d\n", signum, sigint_count);
    if (sigint_count >= 2) {
        printf("Restoring default SIGINT behavior...\n");
        signal(SIGINT, SIG_DFL);
    }
}

int main() {
    signal(SIGINT, custom_signal_handler);
    printf("Press Ctrl+C to generate SIGINT...\n");
    while (1);
    return 0;
}
