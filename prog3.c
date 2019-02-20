//
//  main.c
//  q3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "lib.h"

int main(int argc, char* argv[]) {
    printf("Main Process Started\n");
    int n=(int) atoi (argv[1]);//first input for random num gen
    int y=(int) atoi (argv[2]);//second input for fib num

    
    long int ans;
    int arr[n];
//We seed time into srand() to get random entries each time.
    srand( time(NULL) );
    

    pid_t child;
    printf("Main Process Waits\n");
    child =fork();
    
    //if fork successful
    if (child >= 0) {
        
        // 4 leading spaces.
        if (child == 0){
            printf("    Sort Process created\n");
           
            for (int i=0; i < n ; i++){
                arr[i] = (rand()%100);}
            
            printf("    Random Numbers Generated:\n");
            for (int x=0; x<n ; x++){
                printf("    %d",arr[x]);
                            }
            
            sort(arr,n);
        
            printf("\n    Sorted numebers are:\n");
     
            
            for (int x=0; x<n ; x++){
                printf("    %d",arr[x]);
                
      
            }
            printf ("\n    Sort Process exits\n");

        }
        
        else {
            //Parent Process, 7 leading spaces.
            printf("       Fibonacci process started:\n");
            printf("       Fibonacci Input %d\n",y);
            ans = fib(y);
            printf("       f(%d) is %li\n",y, ans);
            printf("       Fibonacci Process exits.\n");

        }
    }
 
    // If Does not work
    else {
        printf("\nFork Fail\n");
                    return 1;
    }
    


        printf("Main Process Exits.\n");
    return 0;
}
    


