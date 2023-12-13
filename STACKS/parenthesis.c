#include<stdio.h>
#include<stdlib.h>

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

void push(struct stack *s, char value){
    if(isFull(s)){
        printf("STACK OVERFLOW");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
    }
}

char pop(struct stack *s){
    if(isEmpty(s)){
        printf("STACK UNDERFLOW");
        return -1;
    }
    else{
        char value = s->arr[s->top];
        // s->arr[s->top] = NULL;
        s->top--;
        return value;
    }
}

int parenthesisChecker(char *expression){

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(s->size*sizeof(char));

    for(int i = 0; expression[i] != '\0'; i++){
        if(expression[i] == '('){
            push(s, '(');
        }
        else if(expression[i] == ')'){
            if(isEmpty(s)){
                return 0;
            }
            pop(s); 
        }
    }
    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
}

void main()
{

    char *expression = "3*2(8+1)";

    if(parenthesisChecker(expression)){
        printf("PARENTHESIS ARE MATCHING");
    }
    else{
        printf("PARENTHESIS ARE NOT MATCHING");
    }
}