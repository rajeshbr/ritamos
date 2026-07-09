#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
void wait_forever(void) {

  // This is the final loop at the end of your init program
  while (1) {
    int status;

    // This sleeps efficiently until ANY child process exits
    pid_t pid = wait(&status);

    if (pid < 0) {
      // If pid is -1, there are either no children left (ECHILD),
      // or we were interrupted by a signal.
      // We pause briefly to prevent a 100% CPU lockup loop.
      sleep(1);
      continue;
    }

    printf("[INIT] Process %d exited\n", pid);

    // OPTIONAL: If a critical service dies, an init program
    // usually restarts it right here!
    // if (pid == critical_service_pid) {
    //     critical_service_pid = launch_service("my_service", service_args);
    // }
  }
}
