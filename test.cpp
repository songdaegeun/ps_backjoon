#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int *p = (int *)malloc(sizeof(int)); // a1

	printf("(%d) memory address of p: %08x\n", getpid() , p); // a2
	*p = 0; // a3
	while (1) {
		*p = *p + 1;
		printf("(%d) p: %d\n ", getpid() , *p); // a4
	}
	return 0;
 }