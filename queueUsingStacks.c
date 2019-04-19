#include<stdio.h>
#include<stdbool.h>
#define MAX 100
int s1[MAX], s2[MAX];
int top1=-1, top2=-1;


void printS1(){
    int i;
    for(i=top1; i>=0; i--){
        printf("%d ", s1[i]);
    }
    printf("\n");
}
void printS2(){
    int i;
    for(i=top2; i>=0; i--){
        printf("%d ", s2[i]);
    }
    printf("\n");
}
void printQueue(){
    int i;
    printf("\nQueue is ");
    for(i=top1; i>=0; i--){
        printf("%d ", s1[i]);
    }
    printf("\n");
}
int peek1(){
    return s1[top1];
}

int peek2(){
    return s2[top2];
}
bool push1(int val){
    if(top1==MAX-1){
        return false;
    }
    ++top1;
    s1[top1]=val;
    return true;
}
bool push2(int val){
    if(top2==MAX-1){
        return false;
    }
    ++top2;
    s2[top2]=val;
    return true;
}
bool pop1(){
    if(top1==-1)
        return false;
    --top1;
    return true;
}
bool pop2(){
    if(top2==-1)
        return false;
    --top2;
    return true;
}
bool enqueue(int val){
    if(top1==MAX-1)
        return false;
    if(top1!=-1){
        do{
            push2(s1[top1]);
            pop1();
        }while(top1>=0);
        push1(val);
        do{
            push1(s2[top2]);
            pop2();
        }while(top2>=0);
    }
    else{
        push1(val);
    }
    return true;
}
bool dequeue(){
    if(top1==-1)
        return false;
    pop1();
    return true;
}

int main(){
 /*   push1(1);
    push1(2);
    push1(3);
    printS1();  */
    enqueue(2);
    enqueue(3);
    dequeue();
    enqueue(4);
    dequeue();
    printQueue();
}
/*
int main(){
    printQueue();
    enqueue(1);
    printQueue();
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printQueue();
    dequeue();
    dequeue();
    printQueue();

}*/