#include <stdlib.h>

#include "rt.h"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./rt input.svati output.ppm\n");
    return 1;
  }
  return parse_input(argv[1]);
}
