#include <unistd.h>

int setup_hostname(void) {
  sethostname("RitamOS", 6);

  return 0;
}
