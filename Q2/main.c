#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    pid_t pid;
    pid_t unresponsive_pid = -1;
    int i;

    for (i = 1; i <= 3; i++)
    {
        pid = fork();

        if (pid == 0)
        {
            // Child process
            printf("Child %d created with PID: %d\n", i, getpid());

            if (i == 2)
            {
                printf("Child %d is unresponsive...\n", i);

                while (1)
                {
                    sleep(1);
                }
            }
            else
            {
                sleep(3);
                printf("Child %d completed.\n", i);
                exit(0);
            }
        }
        else if (pid > 0)
        {
            // Parent process
            if (i == 2)
            {
                unresponsive_pid = pid;
            }
        }
        else
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }

    // Allow children to execute
    sleep(5);

    printf("\nChecking for unresponsive child...\n");

    if (unresponsive_pid > 0)
    {
        printf("Terminating child with PID %d\n", unresponsive_pid);
        kill(unresponsive_pid, SIGKILL);
    }

    // Wait for all child processes to finish
    while (wait(NULL) > 0)
        ;

    printf("All child processes terminated successfully.\n");

    return 0;
}