#include "task1.h"
#include <stdio.h>
#include <string.h>

#define N 256

int main()
{
    
    char in[N] = {0};
    char out[N] = {0};
    
    printf("Enter string: \n");
    fgets(in, N, stdin);
    
    in[strlen(in) - 1] = '\0';
 
    printf("%s",randomWords(in,out));

    return 0;
}
