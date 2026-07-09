#ifndef INIT_H
#define INIT_H
void init_banner(void);

int mount_filesystems(void);

int create_directories(void);

int setup_hostname(void);

int start_logger(void);
int start_klogd(void);

void start_network(char *);

int start_console(void);
void wait_forever(void);
int start_services(void);
#endif
