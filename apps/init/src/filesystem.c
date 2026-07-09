#include <sys/stat.h>

int create_directories(void) {
  mkdir("/tmp", 0755);

  mkdir("/var", 0755);

  mkdir("/var/log", 0755);

  mkdir("/run", 0755);
  mkdir("/dev/pts", 0755);

  return 0;
}
