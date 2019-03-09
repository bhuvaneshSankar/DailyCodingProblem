#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define sqr(x) x*x
#define INTERVAL 10000
int rangeX;
int rangeY;
bool insideCircle(double x, double y, int r){
    double dist = (x*x) + (y*y);
    if( (dist <=1) )
        return true;
    else 
        return false;
}
double generateRandom(){
    double val;
    
 //   val = (double) ((rand() % (INTERVAL+1)) / INTERVAL);
    val = (double) (rand() % (INTERVAL + 1)) / INTERVAL;
    printf("%lf ", val);
    return val;
}
void calculatePi(int radius){
    
    int pointsWithinCircle=0, pointsOutsideCircle=0;
    int i;
    double x, y, pi;
    for(i=0; i<100000000; i++){
        x = generateRandom();
        y = generateRandom();
        printf("%lf %lf", x, y);
        if(insideCircle(x,y,radius))
            pointsWithinCircle++;
        else 
            pointsOutsideCircle++;
    //    pi = (double)(4*(pointsWithinCircle/pointsOutsideCircle));
        pi = (double)(4 * pointsWithinCircle) / pointsOutsideCircle;
        printf("\n%lf", pi);
    }
    printf("\nfinal value = %lf", pi);

}
int main(){
    
    calculatePi(1);
}