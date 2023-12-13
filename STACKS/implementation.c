#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
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
        return -1;
    }
    else{
        int value = s->arr[s->top];
        s->arr[s->top] = NULL;
        s->top--;
        return value;
    }
}

int peek(struct stack *s, int position){
    int index = s->top-position+1;
    if(index < 0){
        printf("PLEASE ENTER A VALID POSITION");
        return -999;
    }
    else{
        return s->arr[index];
    }
}

void traversal(struct stack *s){
    for(int i = 0; i <= s->top; i++){
        printf("%d\t",s->arr[i]);
    }
    printf("\n");
}

void main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));

    push(s, 5);
    traversal(s);
    push(s, 6);
    traversal(s);
    push(s, 7);
    traversal(s);
    push(s, 8);
    traversal(s);
    push(s, 9);
    traversal(s);
    printf("POPPED %d FROM THE STACK\n", pop(s));
    traversal(s);
}