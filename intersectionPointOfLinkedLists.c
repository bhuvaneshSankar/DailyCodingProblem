#include<stdio.h>        // There are two singly linked lists in a system. By some programming error, 
#include<stdlib.h>       //the end node of one of the linked list got linked to the second list, 
#include<stdbool.h>      //forming an inverted Y shaped list. Write a program to get the point where two linked list merge.                   
                         


struct Node{
    int data;
    struct Node* next;
    bool visited;
};


void printll(struct Node* temp){
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
struct Node* getIntersectNodeByBruteForce(struct Node* h1, struct Node* h2){
    struct Node* temp1 = h1;
    struct Node* temp2 = h2;
    while(temp1!=NULL){
        temp2 = h2;
        while(temp2 != NULL){
            if(temp1 == temp2)
                return temp1;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return -1;
}
struct Node* getIntersectNodeByVisited(struct Node* h1, struct Node* h2){
    struct Node* temp1 = h1;
    struct Node* temp2 = h2;
    while(temp1!=NULL){
        temp1->visited = true;
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        if(temp2->visited == true)
            return temp2;
        temp2 = temp2->next;
    }
    return -1;
}
int getCount(struct Node* temp){
    int count=0;
    while(temp!=NULL){
        ++count;
        temp = temp->next;
    }
    return count;
}
struct Node* getIntersectNodeByDiffNodes(struct Node* h1, struct Node* h2){
    int c1 = getCount(h1);
    int c2 = getCount(h2);
    int diff = abs(c1-c2);
    if(c1>c2){
        int i = diff;
        while(i>0){
            --i;
            h1 = h1->next;
        }
    }
    else{
        int i = diff;
        while(i>0){
            --i;
            h2 = h2->next;
        }
    }
    while(h1!=NULL){
        if(h1==h2)
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return -1;
}
int main(){
    struct Node* newNode; 
  struct Node* head1 = 
            (struct Node*) malloc(sizeof(struct Node)); 
  head1->data  = 10; 
  
  struct Node* head2 = 
            (struct Node*) malloc(sizeof(struct Node)); 
  head2->data  = 3; 
  
  newNode = (struct Node*) malloc (sizeof(struct Node)); 
  newNode->data = 6; 
  head2->next = newNode; 
  
  newNode = (struct Node*) malloc (sizeof(struct Node)); 
  newNode->data = 9; 
  head2->next->next = newNode; 
  
  newNode = (struct Node*) malloc (sizeof(struct Node)); 
  newNode->data = 15; 
  head1->next = newNode; 
  head2->next->next->next  = newNode; 
  
  newNode = (struct Node*) malloc (sizeof(struct Node)); 
  newNode->data = 30; 
  head1->next->next= newNode; 
  
  head1->next->next->next = NULL; 

    struct Node* intersectNode;
    intersectNode = getIntersectNodeByBruteForce(head1, head2);    //o(m*n)
 //   intersectNode = getIntersectNodeByVisited(head1, head2);     //o(m+n) but requires extra space for visited in all the nodes
 //   intersectNode = getIntersectNodeByDiffNodes(head1, head2);   //o(m+n) no extraspace
    printf("%d ", intersectNode->data);
}
