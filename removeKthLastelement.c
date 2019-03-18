#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;


struct node* createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}



int count=1;
struct node* kthnode;
void calcN(struct node* current, int n){
    if(current!=NULL){
        calcN(current->next, n);
        if(count==n){
            kthnode = current;
        }
        ++count;
    }
}
struct node* getKthFromLast(struct node *head, int n)
{
       kthnode = NULL;
       count=1;
       calcN(head, n);
       if(kthnode==NULL)
            return NULL;
        else
            return kthnode;
        
    
}
bool delKthNode(int k){
    struct node* delnode = getKthFromLast(head, k);
    if(delnode==NULL)
        return false;
    struct node* current = head;
    struct node* previousnode = head;
    while(current != delnode){
        previousnode = current;
        current = current->next;
    }
    if(current==head){
        head = head->next;
        free(previousnode);
        return true;
    }
    previousnode->next = current->next;
    free(current);
    return true;

}
void printll(){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main(){
    head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    if(delKthNode(5))
        printll();
    printf("\n");
    if(delKthNode(4))
        printll();
}