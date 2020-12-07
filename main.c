#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    srand(time(NULL));
    printf("parent before forking: %d\n", getpid());

    int f = fork();
    if (f) {
        f = fork();
    }

    if (f) {
        int status;
        int p = wait(&status);
        int time = WEXITSTATUS(status);
        printf("child %d finished after %d seconds\n", p, time);
        printf("parent finished\n");
    }
    else {
        printf("child %d\n", getpid());
        int time = rand() % 9 + 2;
        sleep(time);
        printf("child %d finished\n", getpid());
        return time;
    }
    return 0;
}