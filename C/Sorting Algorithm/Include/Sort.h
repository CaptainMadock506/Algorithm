/* date = March 1st 2022 1:10 pm */

#ifndef _SORT_H
#define _SORT_H

#endif //_SORT_H

#include <math.h>
#include <stdio.h>

// utility functions

void swap(int *xv, int *yv){
    int temp = *xv ; 
    *xv = *yv;
    *yv = temp ; 
}


void displayArray(int *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (i == 0)
            printf("[ %d ,",arr[i]); //std::cout << "[ " << arr[i] << " , ";
        else if (i == arrSize - 1)
            printf("%d ]\n",arr[i]); //std::cout << arr[i] << " ]" << std::endl;
        else
            printf("%d , ",arr[i]); //std::cout << arr[i] << " , ";
    }
}

// sorting algorithm

void bubbleSort(int *arr, int arrSize){
    
    int coutner= 0 ;
    for(int i = 0; i < arrSize-1 ; i++){
        if(counter == arrSize -1)
            break;
        for(int j = 0 ; j < (arrSize-1) - i; j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j],&arr[j+1]);
            else
                counter++ ; 
        }
    }
}


void shuffleSort(int *arr, int arrSize) {
    
    int mid = floor(arrSize / 2);
    int rad = arrSize - 1;
    
    if (arrSize % 2 == 0) {
        
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < ((i == mid - 1) ? 1 : mid); j++) {
                
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
                
                if (arr[rad - j] < arr[(rad - 1) - j])
                    swap(&arr[rad - j], &arr[(rad - 1) - j]);
            }
        }
        
    } else {
        for (int i = 0; i <= mid; i++) {
            for (int j = 0; j < ((i == mid) ? 1 : mid); j++) {
                counter++;
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
                
                if (arr[rad - j] < arr[(rad - 1) - j])
                    swap(&arr[rad - j], &arr[(rad - 1) - j]);
            }
        }
    }
}

void selectionSort(int* arr, int arrSize){
    
    int minVal = 0 , minIndex = 0 ;
    for(int i = 0 ; i < arrSize; i++){
        
        minVal = arr[i] ; minIndex = i ; 
        
        for(int j = i ; j < arrSize; j++ ){
            
            if(arr[j] < minVal){
                minVal = arr[j];
                minIndex = j ; 
            }
        }
        
        swap(&arr[i],&arr[minIndex]);
    }
    
}

void insertionSort(int* arr[], int arrSize){
    
    int key = 0 ; 
    
    for(int i = 1; i < arrSize ; i++){
        key = arr[i];
        for(int j = i; j >= 0; j-- ){
            if(arr[j-1] < key)
                swap(&arr[j],&arr[j-1]);
            else{
                arr[j] = key
            }
        }
    }
}


void combSort(int* arr, int arrSize){
    
    int shrinkRatio = 1.3 ; 
    int gap = arrSize ; 
    bool isSwapped = true ; 
    
    while(isSwapped){
        gap  = floor(gap/shrinkRatio) ; 
        
        if(gap < 1)
            gap = 1  ; 
        
        for(int i = 0 ; i  < arrSize - gap; i++){
            if(arr[i] > arr[i+gap]){
                swap(&arr[i],&arr[i+gap]);
                isSwapped = true ; 
            }else 
                isSwapped = false ; 
        }
    }
}