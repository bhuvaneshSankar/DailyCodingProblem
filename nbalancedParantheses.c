#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int stack[50];
int len=50;
int top=-1;
void push(int val){
		if(top==len-1){
			printf("overflow");
			return;
		}
		else{
			top++;
			stack[top] = val;
		}
	}
	int pop(){
		if(top==-1){
			printf("underflow");
			return -1;
		}
		else{
			int temp = stack[top];
			--top;
			return temp;
		}
	}
	int peek(){
		if(top==-1){
			printf("\nunderflow");
			return -1;
		}
		else{
			return stack[top];
		}
	}
	bool isEmpty(){
		return top==-1 ? true : false;
	}
	int sizeOfStack(){
		return top+1;
	}
	void printStack(){
		for(int i=0; i<top; i++)
			printf("%d ", stack[i]);
		printf("\n");
	}



bool isBalanced(char str[]){
    int length = strlen(str), i;
    for(i=0; i<length; i++){
        if(str[i]=='('){
            push(i);
        }
        else if(str[i]==')'){
            if(isEmpty()){
                return false;
            }
            else{
                pop();
            }
        }
    }
    if(isEmpty()){
        return true;
    }
    else{
        return false;
    }
}
void generateParantheses(int n, int open, int close, bool stopOpen, char str[], int i){
    if(close==n){
        if(isBalanced(str))
            printf("%s\n", str);
        return;
    }
    if(open==n){
        stopOpen = true;
    }
    else{
        stopOpen = false;
    }
    if(stopOpen==false){
        str[i]='(';
        ++open;
    }
    else{
        str[i]=')';
        ++close;
    }
    generateParantheses(n, open, close, stopOpen, str, i+1);
    if(str[i]!=')'){
        str[i]=')';
        --open;
        ++close;
        generateParantheses(n, open, close, stopOpen, str, i+1);
    }
    return;
}
int main(){
    int n=2;
    char str[n*2];
    generateParantheses(n, 0, 0, false, str, 0);
}