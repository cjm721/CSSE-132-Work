#include <stdio.h>

#define SIZE 50

int
sum(int x, int y)
{
  int z = x + y;
  return z;
}

int
main(int argc, char **argv)
{
  char output_string[SIZE] = "Calculating sum\n";
  int output_value;
  
  printf("%s", output_string);
  output_value = sum(5, -4);
  printf("The result is %d\n", output_value);

  return 0;
}
