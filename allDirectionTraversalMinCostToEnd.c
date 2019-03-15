#include<stdio.h>

int minCost=16;
void computeCount(int boolArr[4][4], int flagMat[4][4], int x, int y, int endX, int endY, int r, int c, int count){
    flagMat[x][y]=1;
    if(x==endX && y==endY){
        if(count<minCost)
            minCost=count;
    }
    if(x<0 || x==r || y<0 || y==c)
        return;
    if(boolArr[x][y]==1)
        return;
    if(flagMat[x-1][y]==0)
        computeCount(boolArr, flagMat, x-1, y, endX, endY, r, c, count+1);  //move up
    if(flagMat[x][y-1]==0)
        computeCount(boolArr, flagMat, x, y-1, endX, endY, r, c, count+1);  //move left
    if(flagMat[x][y+1]==0)
        computeCount(boolArr, flagMat, x, y+1, endX, endY, r, c, count+1);  //move right
    if(flagMat[x+1][y]==0)
        computeCount(boolArr, flagMat, x+1, y, endX, endY, r, c, count+1);  //move down
    flagMat[x][y]=0;
}
int main(){
    int boolArr[4][4] = { {0,0,0,0}, {1,0,0,1}, {0,0,0,0}, {0,0,0,0}};
    int startX = 3, startY = 0;
    int endX = 0, endY = 0;
    int flagMat[4][4], i, j, r=4, c=4;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            flagMat[i][j] = 0;
    computeCount(boolArr, flagMat, startX, startY, endX, endY, r, c, 0);
    printf("%d ", minCost);

}