#include<stdio.h>       // auto complete feature using trie data structure.
#include<stdlib.h>      //trie time complexity for search, insertion, deletion is o(n) where n is the length of the string
#include<stdbool.h>
#include<string.h>

#define alpha_size 26
struct TrieNode{
    struct TrieNode* children[alpha_size];
    bool endOfString;
};

struct TrieNode* createNewNode(){
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    int i;
    for(i=0; i<alpha_size; i++)
        newNode->children[i] = NULL;
    newNode->endOfString=false;
    return newNode;
}
int convertCharToIndex(char c){
    return (int)c - (int)'a';
}

void insert(struct TrieNode* head, char str[]){
    int len=strlen(str);
    int level;
    struct TrieNode* current = head;
    for(level=0; level<len; level++){
        int index=convertCharToIndex(str[level]);
        if(current->children[index]==NULL)
            current->children[index] = createNewNode();
        current = current->children[index];
    }
    current->endOfString=true;
}
bool isLastNode(struct TrieNode* head){
    int i;
    for(i=0; i<alpha_size; i++){
        if(head->children[i]!=NULL)
            return false;
    }
    return true;
}
void suggest(struct TrieNode* head, char str[], int level){
    if(head->endOfString==true){
        str[level]='\0';
        printf("%s\n", str);
    }
    if(isLastNode(head))
        return;
    int i;
    for(i=0; i<alpha_size; i++){
        if(head->children[i]!=NULL){
            str[level] = i+'a';
            suggest(head->children[i], str, level+1);
        }
    }
}

void autoComplete(struct TrieNode* head, char query[]){
    int len = strlen(query);
    int level;
    struct  TrieNode* current = head;
    
    for(level=0; level<len; level++){
        int index = convertCharToIndex(query[level]);
    
        if(current->children[index]==NULL)
            return 0;
        current = current->children[index];
    }
  
    suggest(current, query, strlen(query));
}
int main(){
    char strings[][100] = {"dog", "dear", "deer", "hello", "hel", "help", "helpings", "hell"};
    char query[] = "he";
    struct TrieNode* root = createNewNode();
    int length = sizeof(strings)/sizeof(strings[0]);
    int i ;
    for(i=0; i<length; i++){
        insert(root, strings[i]);
    }
    autoComplete(root, query);

    return 0;
}
