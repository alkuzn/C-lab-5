#include "task3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define OUT 0
#define IN 1



char *mixChars(char *in,char *out)
{
    int i=1;
    int index=1;
    int count=0;//счетчик букв
    int rnd=1;//позиция случайной буквы в слове
   char temp='\0';
   
    while(in[count]!=' ' && in[count]!='\0')
        count++;
    
    
    for(i=0;i<count;i++)
        out[i]=in[i];
    
    if(count<=3)
        return out;
    
    else{

        count--;
        do{
            for(index=1;index<count;index++)
            {
                while(rnd==index)
                rnd=rand()%count;
                
                temp=out[index];
                out[index]=out[rnd];
                out[rnd]=temp;
                
            
            }
        }while (strcmp(in,out)==0);
        
        return out;
    }
    
    
}


char *mixLine(char *instr,char *outstr)
{
   if(instr[strlen(instr)-1]=='\n')
       instr[strlen(instr)-1]='\0';
    
    int flag=0;
    int i=0;

    
    while (*instr) {
        if(*instr!=' ' && flag==0)
        {
            flag=1;
        mixChars(instr, outstr);
        }
        else if(instr[i]==' '&& flag==1)
        {
            flag=0;
            *outstr=' ';
        }
        i++;
    }
    return outstr;
}
