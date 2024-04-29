#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        exit(EXIT_SUCCESS); // Child process exits
    } else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        waitpid(child_pid, NULL, 0); // Wait for the specific child process to terminate
        printf("Parent process exiting...\n");
    }

    return 0;
}