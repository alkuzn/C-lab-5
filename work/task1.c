#include "task1.h"
#include<stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
#define SIZE 50


void shuffle(char *words[],int n)//to shuffle words
{
    srand((unsigned)time(0));
    int k=0;
    char *out=NULL;
    
    
    while (n>0) {
        
        n--;
        k=rand()%(n+1);
        
        
        out=words[k];
        words[k]=words[n];
        words[n]=out;
        
    }
}

char *randomWords(char *in, char *out)
{
  
    int numWords=1;
    int index=0;
    int j=0;

    char *words[SIZE]={0};

    char *p_out=out;
  
    int i=0;
    if(  in[strlen(in)-1]=='\n')
      in[strlen(in)-1]='\0';
    

    
    for(int i=1 ;i<strlen(in);i++)// to count num of words
    {
        if( in[i-1]==' ')
            continue;
        else if(in[i]==' ')
            numWords++;
        else index=i;
    }
    if(index+1<strlen(in))
        numWords--;
  
  
  
    char *sep=" ;:.,!?";//to separate words and copy to array words[]
    words[i]=strtok(in,sep);
    i++;
    
    
    while(words[i-1]!=NULL)
    {
        words[i]=strtok(NULL,sep);
        i++;
       
    }

    
    
 //   for(j=0; words[j]; j++)
 //  printf("words: [%s]\n",words[j]);
 
    
    
    shuffle(words, numWords);
    
    char *tmp=NULL;

    for(i=0;i<numWords;i++)
    {
        tmp=words[i];
        while(*tmp!=' ' &&*tmp!='\0')
            *p_out++=*tmp++;
        if(i<numWords-1)
            *p_out++=' ';
    }
    
    *p_out='\0';
 
  
 
    
    //    printf("%s",out);
   

   
    //check out the similarity
    
    if(strcmp(in,out)==1)//true
        puts("\nStrings are identical.\n");
    else
        puts("\nStrings are not identical.\n");
    
    
    
    return out;
}
