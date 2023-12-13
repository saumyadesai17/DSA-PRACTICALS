#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue *q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("QUEUE OVERFLOW");
    }
    else{
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("QUEUE UNDERFLOW");
        return NULL;
    }
    else{
        q->front++;
        int value =  q->arr[q->front];
        return value;
    }
}

void main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 500;
    q->front = q->rear = 0;
    q->arr = (int *)malloc(q->size*sizeof(int));
    
    int node;
    int i=0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    printf("%d\t",i);
    visited[i] = 1;
    enqueue(q, i);
    
    while(!isEmpty(q)){
        int node = dequeue(q);
        for(int j = 0; j < 7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d\t",j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
    
}