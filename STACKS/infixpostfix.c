#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int stackTop(struct stack* s){
    return s->arr[s->top];
}

void push(struct stack *s, int value){
    if(isFull(s)){
        printf("STACK OVERFLOW");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("STACK UNDERFLOW");
        return -999;
    }
    else{
        int value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char c){
    if(c == '*' || c == '/'){
        return 3;
    }
    else if(c == '+' || c == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

char *infixToPostfix(char *infix){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(s->size*sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i = 0; //TRACK INFIX
    int j= 0;  //TRACK POSTFIX
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(s))){
                push(s, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

void main()
{
    char * infix = "a+b*c-d";

    printf("THE POSTFIX EXPRESSION IS %s", infixToPostfix(infix));
}