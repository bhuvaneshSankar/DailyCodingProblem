#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* parent; 
    struct node* left;
    struct node* right;
    bool isLocked;
};
struct node* head = NULL;
struct node* createNewnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->parent = newnode->left = newnode->right = NULL;
    newnode->isLocked = false;
    return newnode;
}

struct node* insert(struct node* parentNode, int leftVal, int rightVal){
    struct node* leftChild = createNewnode(leftVal);
    leftChild->parent = parentNode;
    parentNode->left = leftChild;

    struct node* rightChild = createNewnode(rightVal);
    rightChild->parent = parentNode;
    parentNode->right = rightChild;

    return parentNode;

}

struct node* createBinaryTree(int arr[], int n, int i, struct node* parentNode, struct node* root){
    if(i<n){
        struct node* temp = createNewnode(arr[i]);
        root = temp;
        root->parent = parentNode;
        root->left = createBinaryTree(arr, n, i*2+1, root, root->left);
        root->right = createBinaryTree(arr, n, i*2+2, root, root->right);
    }
    return root;
    
}
void inOrder(struct node* head){
    if(head!=NULL){
        inOrder(head->left);
        printf("%d ", head->data);
        inOrder(head->right);
    }
}
bool preOrderLockChecking(struct node* head){       //return true if all of the nodes in the tree are unlocked
    if(head!=NULL){
        
        if(head->isLocked==true)
            return false;
        preOrderLockChecking(head->left);
        
        preOrderLockChecking(head->right);
        
    }
    return true;
}
bool is_locked(struct node* current){
    if(current->isLocked==true)
        return true;
    else 
        return false;
}
bool isLeaf(struct node* current){
    if(current->left==NULL && current->right==NULL)
        return true;
    else 
        return false;
}
bool lock(struct node* root){
    struct node* current = root;
    //check descendats
     if(!isLeaf(current)){
        if(preOrderLockChecking(root->left)==true){
            if(preOrderLockChecking(root->right)==true){
                root->isLocked=true;
                return true;
            }
        }
    }
    //check ascendants
    if(root!=head){
        current = current->parent;
        while(current!=NULL){
            if(current->isLocked==true)
                return false;
            current = current->parent;
        }
        root->isLocked=true;
        return true;
    }
}

bool unlock(struct node* root){
    struct node* current = root;
    //check descendats
    if(!isLeaf(current)){
        if(preOrderLockChecking(current->left)==true && preOrderLockChecking(current->right)==true){
            root->isLocked=false;
            return true;
        }
    }
   
    //check ascendants
    current = current->parent;
    while(current!=NULL){
        if(current->isLocked==true)
            return false;
        current = current->parent;
    }
    root->isLocked=false;
    return true;
}
void printToHead(struct node* current){
    while(current->left!=NULL){
        current = current->left;
    }
    while(current!=head){
        printf("%d ", current->data);
        current = current->parent;
    }
}   
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    head = createBinaryTree(arr, n, 0, NULL, head);
    //  inOrder(head);
  //  preOrder(head);
  //  printToHead(head);
    printf("%d \n", is_locked(head->left));
    printf("%d \n", lock(head->left->left));
    printf("%d \n", is_locked(head->left->left));
    printf("%d \n", lock(head->left->left->left));
    printf("%d \n", lock(head->left->left->right));
    printf("%d \n", unlock(head->left->left));
    printf("%d \n", lock(head->left->left->left));   
    printf("%d \n", lock(head->left));
    printf("%d \n", lock(head->left->left));
    printf("%d \n", lock(head->right)); 
    printf("%d \n", lock(head)); 
    printf("%d \n", unlock(head));
//    printf("%d \n", lock(head->right->left->right));
    
   
}