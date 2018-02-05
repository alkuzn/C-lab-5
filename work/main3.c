#include "task3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


    
int main()
{
     srand((unsigned)time(NULL));
    
    char strIn[NUM]={0};
    char strOut[NUM]={0};
    
    FILE *input_F = fopen ("in.txt", "r");
   FILE *output_F = fopen("out.txt", "w");
   // FILE *output_F=stdin;
    
    if (input_F == NULL ||output_F==NULL)
    {
        perror("fopen");
        return 1;
    }
    
    
    while(fgets(strIn,NUM,input_F)!=NULL)
    {
        fputs(mixLine(strIn,strOut),output_F);
        if(*strIn!='\n')
            fputc('\n',output_F);
    }
    
    
    fclose(input_F);
    fclose(output_F);
    
    
    return 0;
}
                 
