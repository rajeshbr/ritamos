#include "../include/init.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
  init_banner();

  if (create_directories())
    return 1;

  if (mount_filesystems())
    return 1;

  if (setup_hostname())
    return 1;

  if (start_logger())
    return 1;
  if (start_klogd())
    return 1;

  start_network("eth0");
  if (start_services())
    return 1;
  if (start_console())
    return 1;
  wait_forever();
}
