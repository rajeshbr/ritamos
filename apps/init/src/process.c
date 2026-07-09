#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * Launches a background service safely and securely.
 * @param name  A friendly name for logging.
 * @param argv  Argument array (argv[0] is the command, list ends with NULL).
 * @return      The PID of the started service, or -1 on failure.
 */
pid_t launch_service(const char *name, char *const argv[]) {
  // 1. Basic sanity check to prevent crashes
  if (!argv || !argv[0]) {
    fprintf(stderr, "[INIT ERROR] Invalid arguments passed for %s\n", name);
    return -1;
  }

  pid_t pid = fork();

  // 2. Handle fork failure early
  if (pid < 0) {
    perror("[INIT ERROR] Fork failed");
    return -1;
  }

  // 3. Child Process Code
  if (pid == 0) {
    printf("[INIT] Starting %s...\n", name);

    // OPTIONAL SECURITY UPGRADE:
    // Un-comment below to isolate the service in its own process group.
    // This stops Ctrl+C in the terminal from killing your background service.
    // setpgid(0, 0);

    // Execute using PATH lookup
    execvp(argv[0], argv);

    // If execvp fails, print a descriptive error (e.g., "Permission denied" or
    // "File not found")
    fprintf(stderr, "[INIT ERROR] Failed to execute %s (%s): %m\n", name,
            argv[0]);

    // Use _exit instead of exit inside a failed fork child to avoid
    // accidentally flushing parent stdio buffers twice.
    _exit(EXIT_FAILURE);
  }

  // 4. Parent Process Code
  printf("[INIT] %s successfully started with PID: %d\n", name, pid);
  return pid;
}
