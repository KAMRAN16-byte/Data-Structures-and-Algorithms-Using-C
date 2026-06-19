//
// Created by Development on 19-06-2026.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct Queue {
    int front,size,arr[MAX];
};


struct Queue* initQueue() {
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
    newQueue->front = newQueue->size = 0;
    return newQueue;
}

int isFull(const struct Queue *queue) {
    return queue->size == MAX;
}

int isEmpty(const struct Queue *queue) {
    return queue->size == 0;
}

void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[(queue->front + queue->size) % MAX] = data;
    queue->size++;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    const int data = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    return data;
}

void printQueue(const struct Queue *queue) {
    if (isEmpty(queue)) {
        return;
    }
    for (int i = 0; i < queue->size; i++) {
        printf("%d->",queue->arr[(queue->front + i) % MAX]);
    }
}

int main() {
    struct Queue *queue = initQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 30);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 30);
    enqueue(queue, 30);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    printf("\n");
    free(queue);
    return 0;
}



