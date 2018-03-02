
#include "task2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearMatrix(char(*arr)[M])//to fill arr with spaces
{
     for(int row=0;row<M;row++)
         for(int column=0;column<M;column++)
            arr[row][column]=' ';
 
}
void fillMatrix(char(*arr)[M])//to fill with '*'
{
    srand((unsigned)time(NULL));
   
        for(int row=0;row<M/4;row++)
             for(int column=0;column<M/4;column++)
                 arr[rand()%(M/2)][rand()%(M/2)]='*';
  
    
}
void setMatrix(char (*arr)[M])
{
    int x;
    int y;
    
     y=M/2;
    
    for(int row=0;row<M/2;row++)
    {
        x=M/2-1;
        for(int column=M/2;column<M;column++)
        {
       
            arr[row][column]=arr[row][x--];
        }
       
    }
    
    for(int row=M/2;row<M;row++)
    {
      
        y--;
        for(int column=0;column<M;column++)
        {
           
            arr[row][column]=arr[y][column];
        }
    }
    
    
}
void printMatrix(char(*arr)[M])
{
    for(int row=0;row<M;row++)
    {
        for(int column=0;column<M;column++)
        {
            printf("%c",arr[row][column]);
            
        }
        printf("\n");
    }
    
}
