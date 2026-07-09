#include "process.h"
#include <stdio.h>
int start_logger(void) {
  char *argv[] = {"/sbin/syslogd", "-n", NULL};

  if (launch_service("syslogd", argv) < 0)
    return -1;

  return 0;
}

int start_klogd(void) {
  char *argv[] = {"/sbin/klogd", "-n", NULL};

  if (launch_service("klogd", argv) < 0)
    return -1;

  return 0;
}
