#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct queue *q){
    int check = ((q->rear+1)%(q->size));
    if(check == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("QUEUE OVERFLOW\n");
    }
    else{
        q->rear = (q->rear+1)%(q->size);
        q->arr[q->rear] = value;
        printf("%d INSERTED AT POSITION %d\n", value, q->rear);
    }
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("QUEUE UNDERFLOW\n");
        return -999;
    }
    else{
        q->front = (q->front+1)%(q->size);
        int value = q->arr[q->front];
        return value;
    }
}

void main()
{
    struct queue *q;
    q->size = 5;
    q->front = q->rear = 0;
    q->arr = (int *)malloc(q->size*sizeof(int));

    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 11);
    printf("%d HAS BEEN DEQUEUED\n",dequeue(q));
    printf("%d HAS BEEN DEQUEUED\n",dequeue(q));
    enqueue(q, 9);
    enqueue(q, 10);
}