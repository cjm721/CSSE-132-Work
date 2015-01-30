#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_ARRAY_SIZE 20

void
process_int_array(int int_array[])
{
	int i;

	printf("\n\nProcessing integer array\n");

	for(i=0; i<INT_ARRAY_SIZE; i++) {
		int_array[i] = i + 20;
	}
}

int
multiply(int x, int y)
{
	int i = 0;
  int product = 1;
  
	for(i=0; i<y; i++) {
		product = sum(product, x);
  }

	printf("The product of %d and %d is %d\n", x, y, product);
}

int
sum(int x, int y)
{
	int z = x + y;

	return z;
}

int
main(int argc, char **argv)
{
	int int_array[INT_ARRAY_SIZE];
  int a, b, c;

	process_int_array(int_array);

	a = 2;
	b = 5;

	c = multiply(a,b);

	return 0;
}
