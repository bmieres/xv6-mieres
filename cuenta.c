#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  printf(1,"Numero de procesos %d\n", getprocs());
  exit();
}
