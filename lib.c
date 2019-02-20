//
//  lib.c
//  q3
//
//  Created by Delwyn on 2017-03-20.
//  Copyright (c) 2017 Delwyn. All rights reserved.
//

#include <stdio.h>
#include"lib.h"

void sort(int arr[], int size){
    
    for (int i=0; i<size; i++){
        
        for(int j=size-1;j>i;j--){
            if (arr[j]<arr[j-1]){
                int *a=&arr[j];
                int *b=&arr[j-1];
                int temp = *a;
                *a=*b;
                *b=temp;}
        }
    }
    
    
    return ;
}

long int fib(int number){
    if (number ==1 || number ==2){
        return 1;}
    else
        return fib(number-2) + fib(number-1);
    
}
