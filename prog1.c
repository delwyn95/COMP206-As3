//
//  main.c
//  q1

#include <stdio.h>
#include <stdlib.h>

long int fib (int num);
int sum(int num[]);

int main(int argc, const char * argv[]) {
    
    // Open up file
    FILE *input=fopen(argv[1],"r");
    int i=0;
    int array[999];
    int number;
    
    //Scan number from file into array
    while (fscanf(input,"%d", &number ) > 0){
        array[i] = number;
        i++;
    }

    
    printf("\nThe sum of numbers is %d\n", sum(array));
    
    int j=0;
    while (array[j] != '\0'){
        printf("fib(%d) is %ld\n", array[j], fib(array[j]));
        j++;
    }
    fclose(input);
    
    return 0;
}


long int fib(int num){
    
    //base case
    if (num == 1 || num ==2){
        return 1;
    }
    else {
        return fib(num-2) + fib(num-1);
    }
}

int sum(int num[]){
    int sum=0;
    int index=0;
    
    while (num[index] != '\0'){
        sum = sum + num[index];
        index++;
    }
    return sum;
}