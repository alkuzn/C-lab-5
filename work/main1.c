#include "task1.h"

int main()
{
	int i = 0, len = 0,j=0;
	char buf[SIZE] = {0};
	char *in[SIZE] ;
	char *out[SIZE] ;
	char *p;
	printf("Enter line of words: \n");
	fgets(buf, SIZE, stdin);
	p=randomWords(buf, out);
	printf("%s \n", p);

	
	return 0;
}