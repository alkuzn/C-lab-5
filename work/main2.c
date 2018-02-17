#include "task2.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
//#include <term.h>
#define M 40



int main() {

    char arr [M][M]={0};
   
    
    while(1)
    {
        clearMatrix(arr);
    
        fillMatrix(arr);
        
        setMatrix(arr);

      system ("clear");
        printMatrix(arr);
        sleep(1);
    
    }
    
    return 0;
}
