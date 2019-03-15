#include<stdio.h>
#include<stdbool.h>
bool checkerBoard[10][10];

bool isSafe(int row, int col, int n){
    if(checkerBoard[row][col]==true)
        return false;
    int i, j;
    for(i=row; i<n; i++){   // check lower column
        if(checkerBoard[i][col]==true)
            return false;
    }
    for(i=row; i>=0; i--){  // check upper column
        if(checkerBoard[i][col]==true)
            return false;
    }
    for(i=col; i<n; i++){   // check right side
        if(checkerBoard[row][i] == true)
            return false;
    }
    for(i=col; i>=0; i--){   // check left side
        if(checkerBoard[row][i] == true)
            return false;
    }
    for(i=row, j=col; i<n && j<n; i++, j++){    //check lower right diagonal
        if(checkerBoard[i][j]==true)
            return false;
    }
    for(i=row, j=col; i>=0 && j>=0; i--, j--){    //check upper left diagonal
        if(checkerBoard[i][j]==true)
            return false;
    }
    for(i=row, j=col; i>=0 && j<n; i--, j++){   //check upper right diagonal
        if(checkerBoard[i][j]==true)
            return false;
    }
    for(i=row, j=col; i<n && j>=0; i++, j--){   //check upper right diagonal
        if(checkerBoard[i][j]==true)
            return false;
    }
    return true;
}
void printArr(int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(checkerBoard[i][j]==true)
                printf("%d ", j+1);
        }
    }
    printf("\n");
}
void nqueensbt(int row, int n){
    if(row==n) {
        printArr(n);
        return true;
    }
    bool isPlaced = false;
    int i;
    for(i=0; i<n; i++){
        if(isSafe(row, i, n)){
         //   printf("row = %d, i = %d\n", row, i);
            checkerBoard[row][i] = true;
            isPlaced = true;
          /*  if(nqueensbt(row+1, n)){
                if(row==0)
                    printArr(n);
                return true;
            } */
            nqueensbt(row+1, n);
            checkerBoard[row][i] = false;
            isPlaced = false;
            
        }
    }
    if(isPlaced==false)
        return false;
}

int main(){
    int n = 2;
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            checkerBoard[i][j] = false;
    }
    nqueensbt(0, n);
}