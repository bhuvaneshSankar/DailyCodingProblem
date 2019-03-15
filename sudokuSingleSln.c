#include<stdio.h>
#include<stdbool.h>
const int r= 9;
const int c = 9;

bool isSafe(int checker[10][10],int x,int y,int num){
    int startX, startY;
    startX = x-(x%3);
    startY = y-(y%3);
 //   printf("\n%d %d \n", startX, startY);
    int i,j;
    for(i=startX; i<startX+3; ++i){         //checks in the current box
        for(j=startY; j<startY+3; ++j){
            if(checker[i][j]==num)
                return false;
        }
    }
    //checking in the current row;
    for(j=0; j<c; j++){
        if(checker[x][j]==num)
            return false;
    }

    //checking in the current column;
    for(i=0; i<r; i++){
        if(checker[i][y]==num)
            return false;
    }
    return true;
}
bool solveSudoku(int checker[10][10], int x, int y){
    if(y==c){
        y=0;
        x += 1;
    }
    if(x==r)
        return true;
    if(checker[x][y]==0){
        int i;
        for(i=1; i<=9; i++){
            if(isSafe(checker, x, y, i)){
                checker[x][y] = i;
                if(solveSudoku(checker, x, y+1)==true){
                    return true;
                }
                else{
                    checker[x][y]=0;
                }
            }
        }
        return false;
    }
    else{
        if(solveSudoku(checker, x, y+1)==true)
            return true;
    }
}
void printSudoku(int checker[10][10]){
    int i, j;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            printf("%d ", checker[i][j]);
        }
        printf("\n");
    }
}
int main(){
  //  int checker[10][10] = { {0,3,0,0,0,0}, {2,0,0,7,0,0}, {0,0,9,0,0,2} };
  //  int checker[10][10] = { {0,3,0}, {2,0,0}, {0,0,9} };
  int checker[10][10] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(solveSudoku(checker, 0, 0)==true){
        printSudoku(checker);
    }
    else
        printf("\nNo solution exists");
}