#include <stdio.h>  //smallest positive integer that is not present in the array
#include <stdlib.h> //time complexity = o(n) and space complexity = o(1)
#include <math.h>
void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}  
int findShift(int arr[], int size){
    int swapIndex=0, i;
    for(i=0; i<size; i++){
        if(arr[i]<=0){
            if(i==swapIndex)
                swapIndex++;
            else{
                swap(&arr[i], &arr[swapIndex]);
                swapIndex++;
            }
        }
    }
    return swapIndex;
}
int findMissingInteger(int arr[], int size){
    int i;
    for(i=0; i<size; i++){
        int val = abs(arr[i]);
        if(val-1<size && arr[val-1]>=0){
            arr[val-1] = -arr[val-1];
        }
    }
    for(i=0; i<size; i++){
        if(arr[i]>0)
            return i+1;
    }
    return size+1;
}
int main() 
{ 
//int arr[] = {0, 10, 2, -10, -20}; 
int arr[] = {10,-20,30,40,50};
//int arr[] = {1,2,3,4,5};
int size = sizeof(arr)/sizeof(arr[0]);
int shift = findShift(arr, size);
int missingInteger = findMissingInteger(arr+shift, size-shift);
printf("%d ", missingInteger);

return 0; 
}