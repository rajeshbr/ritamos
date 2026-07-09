#include "process.h"
#include <stdio.h>
#include <unistd.h>
int start_console(void) {

  char *argv[] = {"/bin/sh", NULL};

  if (launch_service("shell", argv) < 0)
    return -1;

  return 0;
}
