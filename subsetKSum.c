#include<stdio.h>
int count=0;
void printArr(int arr[], int copyArr[], int len){
    int i;
    for(i=0; i<len; i++){
        if(copyArr[i]==1){
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
void findKSum(int arr[], int len, int k, int start, int sum, int copyArr[]){
    int copy;
    if(start==len){
        return;
    }
    if(sum>k){
        return;
    }
    int i;
    for(i=start; i<len; i++){
        copy = sum;
        sum = sum + arr[i];
        copyArr[i]=1;
        if(sum==k){
            count += 1;
            printArr(arr, copyArr, len);
        }
        findKSum(arr, len, k, i+1, sum, copyArr);
        sum = copy;             // backtrack and check for other possibilities
        copyArr[i]=0;           // backtrack by making the copyarr as not visited
    }

}
int main(){
  //  int arr[]={2,3,5,6,8,10};
  //  int arr[] = {2,4,2,2,1,3,3};
  //  int arr[] = {1,2,2,2,3,3,4};
    int arr[] = {2, 23, 12, 12, 19, 18, 5, 8, 6, 13, 24, 18, 11, 5, 3, 23};
  //  int arr[] = {2,2,4};
  //  int arr[] = {2,3,5};
    int len = sizeof(arr)/sizeof(arr[0]);
 //   printf("%d ", len);
 //   int len = 3;
    int k = 59;
    int copyArr[100], i;
    for(i=0; i<len; i++){
        copyArr[i]=0;
    }
    findKSum(arr, len, k, 0, 0, copyArr);
    if(count==0)
        printf("\n-1");
    else
        printf("\ncount = %d", count);  
}