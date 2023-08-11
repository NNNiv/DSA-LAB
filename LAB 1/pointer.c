#include <stdio.h>

int main()
{
  int num = 5;
  int *p = &num;

  printf("The value of variable: %d\n", num);
  printf("The address of variable: %p\n", &num);
  printf("The value of the pointer: %p\n", p);
  printf("The value pointed by the pointer: %d\n", *p);

  return 0;
}
