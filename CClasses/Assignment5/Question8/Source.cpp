#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define print(s) printf("token"#s"=%d",token##s)
#define x 10 
int main()
{
	int token9 = 100;
	print(9);
#ifdef x
	printf("hello\n");     
#else
	printf("hii\n");       
#endif
	return 0;
}