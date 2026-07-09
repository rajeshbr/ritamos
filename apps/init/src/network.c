#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Helper function to bring up network interfaces using the system tool
void run_command(char *args[]) {
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    execv(args[0], args);
    // If execv returns, an error occurred
    perror("Exec failed");
    exit(EXIT_FAILURE);
  } else if (pid > 0) {
    // Parent process waits for configuration setup to complete
    int status;
    waitpid(pid, &status, 0);
  } else {
    perror("Fork failed");
  }
}

void start_network(const char *interface) {
  // 1. Always bring up the loopback interface (lo) first
  char *ifconfig_lo[] = {"/sbin/ifconfig", "lo", "127.0.0.1", "up", NULL};
  run_command(ifconfig_lo);

  // 2. Bring up the tablet's physical interface (e.g., wlan0 or eth0)
  char *ifconfig_net[] = {"/sbin/ifconfig", (char *)interface, "up", NULL};
  run_command(ifconfig_net);

  // 3. Start udhcpc in the background
  pid_t pid = fork();
  if (pid == 0) {
    // Arguments for udhcpc
    char *udhcpc_args[] = {
        "/sbin/udhcpc",
        "-b", // Fork to background if no lease
        "-i",
        (char *)interface, // Target network interface
        "-s",
        "/usr/share/udhcpc/default.script", // Script that actually sets the IP
        "-p",
        "/var/run/udhcpc.pid", // PID file location
        NULL};

    printf("[init] Starting udhcpc for %s...\n", interface);
    execv(udhcpc_args[0], udhcpc_args);

    // This line only runs if execv fails
    perror("[init] Failed to start udhcpc");
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("[init] Fork for udhcpc failed");
  }

  // Parent continues running the init loop immediately.
  // We do NOT waitpid() for udhcpc because it runs continuously to manage the
  // lease.
}
