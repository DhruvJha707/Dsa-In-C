/*implementing queue using array */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct queue{
    int items[MAX];
    int front;
    int rear;
};

void init(struct queue *q){
    q->front=-1;
    q->rear=-1;
}

int isFull(struct queue *q){
    if(q->rear==MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct queue *q){
    if(q->front==-1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q,int value){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    
    else{
        if(q->front==-1)
            q->front=0;
        q->rear++;
        q->items[q->rear]=value;
    }
}

int dequeue(struct queue *q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    else{
        item=q->items[q->front];

        q->front++;

        if(q->front>q->rear){
            q->front=-1;
            q->rear=-1;
        }
        return item;
    }
}

void display(struct queue *q){
    int i;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are: ");
        for(i=q->front; i<=q->rear; i++){
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}