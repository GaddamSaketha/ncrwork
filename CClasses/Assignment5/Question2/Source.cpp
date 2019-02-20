#include <stdio.h>
union first
{
	char name[30];
	int value;
} a;

struct second
{
	char name[30];
	int value;
} b;

int main()
{
	printf("size of union = %d bytes", sizeof(a));
	printf("\nsize of structure = %d bytes", sizeof(b));
	return 0;
}
