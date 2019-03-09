#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
struct node{
    int data;
    struct node* both;
};

struct node* head = NULL;

struct node* createNode(int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->both = NULL;
    return newNode;
}
struct node* xor(struct node* a, struct node* b){
    return (struct node*)( (uintptr_t)(a) ^ (uintptr_t)(b) );
}
struct node* insert(struct node* head, int data){
    struct node* newNode = createNode(data);
    if(head==NULL){
        head = newNode;
        return head;
    }
    else{
        struct node* previous=NULL;
        struct node* current=NULL;
        struct node* temp = head;
        while(temp->both!=NULL){
            current = temp;
            temp = xor(previous, current->both);
            previous = current;
        }
        temp->both = xor(previous, newNode);
        return head;
    }
}

void printLL(struct node* head){
    struct node* temp = head;
    struct node* previous = NULL;
    struct node* current = NULL;
    while(temp->both != NULL){
        current = temp;
        printf("%d ", temp->data);
        temp = xor(previous, current->both);
        previous = current;
        
    } 
    printf("%d ", temp->data);
}
void reversePrint(struct node* head){
    struct node* temp = head;
    struct node* previous = NULL;
    struct node* current = NULL;
    while(temp->both!=NULL){
        current = temp;
        temp = xor(previous, current->both);
        previous = current;
    }
    printf("%d ", temp->data);
    while(previous!=head){
        current = previous;
        printf("%d ", previous->data);
        previous = xor(temp, current->both);
        temp = current;
    }
    printf("%d ", previous->data);  
}
int getValue(struct node* head, int index){
    int i;
    struct node* previous = NULL;
    struct node* current = NULL;
    struct node* temp = head;
    for(i=1; i<index; i++){
        current = temp;
        temp = xor(previous, current->both);
        previous = current;
    }
    return temp->data;
}
int main(){
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    printLL(head);
    printf("\nreverse\n");
    reversePrint(head);
    printf("%d ", getValue(head, 5));
}