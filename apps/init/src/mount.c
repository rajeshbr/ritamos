#include <stdio.h>
#include <sys/mount.h>
#include <unistd.h>
int mount_filesystems(void) {
  printf("[INIT] Mounting proc...\n");

  mount("proc", "/proc", "proc", 0, NULL);

  printf("[INIT] Mounting sys...\n");

  mount("sysfs", "/sys", "sysfs", 0, NULL);

  printf("[INIT] Mounting dev...\n");

  mount("devtmpfs", "/dev", "devtmpfs", 0, NULL);

  mount("tmpfs", "/run", "tmpfs", 0, "mode=0755,size=16M");
  mount("devpts", "/dev/pts", "devpts", 0, "mode=620,ptmxmode=666");
  symlink("pts/ptmx", "/dev/ptmx");

  return 0;
}
