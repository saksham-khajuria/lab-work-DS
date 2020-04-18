//InFix to PostFix Conversion Implementation in C by Saksham Khajuria,IT ,11912058
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure of Stack
struct Stack{
    int top;
    char *arr;
    int total;
};

//function that returns a stack with a specific capacity
struct Stack* createStack(int capacity){
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
    newStack->total = capacity;
    newStack->top = -1;
    newStack->arr = (char*)malloc(sizeof(char)*capacity);
    return newStack;
}

//to check if stack is full
int isFull(struct Stack* stack){
    return stack->top == stack->top - 1;
}

//to check is stack is empty
int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

//to return the top of the stack
char peek(struct Stack* stack){
    return stack->arr[stack->top];
}

//push function
void push(struct Stack* stack,char ch){
    stack->arr[++stack->top] = ch;
}

//pop function
char pop(struct Stack* stack){
    if(isEmpty(stack)){
        return 'F';
    }
    return stack->arr[stack->top--];
}

//to check operand
int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

//return precedence
int precendence(char ch){
    switch(ch){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

//Conversion to PostFix algorithm
int InfixToPostFix(char *str){
    struct Stack* newStack = createStack(strlen(str));
    int i,j;
    for(i=0,j=-1;str[i];++i){
        if(isOperand(str[i])){
            str[++j] = str[i];      
        }
        else if(str[i] == '('){
            push(newStack,str[i]);          //if ( is found push it to stack
        }
        else if(str[i] == ')' ){
            while(!isEmpty(newStack) && peek(newStack) != '('){
                str[++j] = pop(newStack);       //if ) is found pop until ( is found
            }
            pop(newStack);
        }
        else{
            while(!isEmpty(newStack) && precendence(str[i])<=precendence(peek(newStack))){
                str[++j] = pop(newStack);           //is precendence is less then pop to the string
            }
            push(newStack,str[i]);                  //push to the stack
        }                                           
    }
    while(!isEmpty(newStack)){
        str[++j] = pop(newStack);                   //pop all the items from stack
    }
    str[++j] = '\0';
    printf("%s",str);
}

int main(){
    char str[] = "a+b*(f+g)^(c^d)-i";
    InfixToPostFix(str);
    return 0;
}
