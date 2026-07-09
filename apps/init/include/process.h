#ifndef PROCESS_H
#define PROCESS_H

#include <sys/types.h>

pid_t launch_service(const char *name, char *const argv[]);

#endif
