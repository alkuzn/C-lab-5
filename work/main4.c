#include "task4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    
    char strIn[SIZE];
    char strOut[SIZE];
    
    FILE *input_F = fopen ("in.txt", "r");
    FILE *output_F = fopen("out.txt", "w");
    

    if (input_F == NULL ||output_F==NULL)
    {
        perror("fopen");
        return 1;
    }
    
  
        while(fgets(strIn,SIZE,input_F)!=NULL)
        {
            fputs(randomWords((char*)strIn, (char*)strOut),output_F);
        if(*strIn!='\n')
            fputc('\n',output_F);
        }
    

    fclose(input_F);
    fclose(output_F);
    

    return 0;
}

