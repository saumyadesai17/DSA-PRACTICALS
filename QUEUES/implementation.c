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
        return -999;
    }
    else{
        q->front++;
        int value = q->arr[q->front];
        return value;
    }
}

void main()
{
    struct queue *q;
    q->size = 4;
    q->front, q->rear = -1;
    q->arr = (int *)malloc(q->size*sizeof(int));

    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);

    printf("%d\n",isEmpty(q));
    printf("%d",isFull(q));
}
