#include "task3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char *mixChars(char *in,char *out)
{
    char wordIn[20]={0};
    int j=1,len=0,index=1;
    char temp=0;
    strcpy(wordIn, in);
    
   // printf("wordIn: %s\n", wordIn);
    
    
    len=strlen(wordIn)-2;
    
    
    for(j=1;j<len;j++) {
        index = j;
        while(index==j)
            index=rand() % len+1;
      
        
        
        //swap
        temp = wordIn[j];
        wordIn[j] = wordIn[index];
        wordIn[index] = temp;
        
    }
    
  //   printf("after mix Chars wordIn: %s\n", wordIn);
    
    
    strcpy(out,wordIn);
    
    
  //  printf("in: %s out: %s\n",in,out);
    
    return out;

}


char *mixLine(char *instr,char *outstr)
{
 
    char temp[NUM]={'\0'};
    char wordOut[NUM]={'\0'};
    char *P_out=outstr;
    char *p_wordOut=wordOut;
    char *P_temp=temp;
    
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
    
    
    char *words[NUM]={0};
   
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
        wordOut[i]=*p_words;
        
        
     mixChars(p_words,wordOut);//в wordOut хранятся уже перевернутые слова
  
        
      //    wordOut[i]=' ';//при попытке добавиь пробел, затираются символы, причем неравномерно
      //  i++;
    
      strcat(temp,wordOut); //здесь копируем в temp слова из wordOut
}
    printf("temp:%s", temp);
    strcat(outstr,temp);
    return outstr;
}
