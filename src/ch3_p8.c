#include <stdio.h>

int main(void) {
  for (int i = 0; i < 5;) {
    i++;
    printf("Loop %d, variable i = %d\n", i, i);
  }
  return 0;
}
