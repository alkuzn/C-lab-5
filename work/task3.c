#include "task3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define IN 1
#define OUT 0

char *mixChars(char *in,char *out)
{
 //   printf("mixChars:\n");
    srand((unsigned)time(NULL));
    int j=1,len=0,index=1;
    char temp=0;
    char *Pin=in;
    
    
    len=strlen(in)-2;
    
    
    for(j=1;j<len;j++) {
        index = j;
        while(index==j)
            index=rand() % len+1;
      
        
        //swap
        temp = in[j];
        in[j] = in[index];
        in[index] = temp;
        
    }
    
    
    out=Pin;
    
  //   printf("in: %s out: %s\n",in,out);
    
    return out;

}


char *mixLine(char *instr,char *outstr)
{
 
    char wordIn[N]={0};
    char wordOut[N]={0};
    char *P_out=outstr;
    char *p_wordOut=NULL;
    
    
    int i=0,j=0;
    int len=0;
    len=strlen(instr);
    
    
    if(instr[len-1]=='\0')
        instr[len-1]='\n';
    
    int numWords=1;
    int index=0;
    
    for(int i=1 ;i<strlen(instr);i++)
    {
        if( instr[i-1]==' ')
            continue;
        else if(instr[i]==' ')
            numWords++;
        else index=i;
    }
    if(index+1<strlen(instr))
        numWords--;
    
  
    
    
    
    char *words[N]={0};
   
    char *sep=" ;:.,!?";
    words[i]=strtok(instr,sep);
    i++;

    
    while(words[i-1]!=NULL)
    {
        words[i]=strtok(NULL,sep);
        i++;
    }
  
   

    char *p_words=NULL;

    
    for(i=0;i<numWords;i++)
    {
        p_words=words[i];
       
 
    // mixChars(p_words,wordOut);
      
printf("%s",  mixChars(p_words, wordOut));
 
         p_wordOut=&wordOut[i];
      
     
           p_wordOut=&wordOut[i];
            if(*p_wordOut==p_wordOut[strlen(p_wordOut)])
                 *p_wordOut++=' ';
             *P_out++=*p_wordOut++;
            

     
        
   for(int j=0;j<strlen((char*)words);j++)
   {    p_wordOut=*(words+j);
       *P_out++=(*p_wordOut)++;
         *P_out++=' ';
     }
    
        
    }
       while (*instr!='\0')
       {
   
            *P_out++=*p_wordOut++;
          
       }
    
   
    
    *P_out='\0';
   *P_out='\n';

    
    

   outstr=P_out;
    
   // printf("p_out: %s\n",(char*)P_out);
    printf("str: %s\n",(char*)outstr);
    
    
    return outstr;
}
