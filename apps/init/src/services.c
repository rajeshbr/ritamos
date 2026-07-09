#include "../include/process.h"
#include <stdio.h>

typedef struct {
  const char *name;

  char **argv;

  int restart;
  int pid;
} Service;

int start_services(void) {

  char *udev_args[] = {"/sbin/udevd", "--daemon", NULL};
  char *udev_trigger[] = {"/sbin/udevadm", "trigger", NULL};
  char *udev_settle[] = {"/sbin/udevadm", "settle", NULL};
  char *session[] = {"/usr/bin/ritamos-session", NULL};

  Service services[] = {{"udev", udev_args, 1},
                        {"udev_trigger", udev_trigger, 1},
                        {"udev_settle", udev_settle, 1},
                        {"ritamos-session", session, 1}};

  int SERVICE_COUNT = sizeof(services) / sizeof(services[0]);

  for (int i = 0; i < SERVICE_COUNT; i++) {
    services[i].pid = launch_service(services[i].name, services[i].argv);
  }

  return 0;
}
