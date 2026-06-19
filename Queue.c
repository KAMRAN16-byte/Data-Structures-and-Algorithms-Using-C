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
    struct Queue *newQueue = malloc(sizeof(struct Queue));
    newQueue->front = newQueue->size = 0;
    return newQueue;
}

int isFull(const struct Queue *queue) {
    return queue->size == MAX;
}

int isEmpty(const struct Queue *queue) {
    return queue->size == 0;
}

void enqueue(struct Queue *queue, const int data) {
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

void peak(const struct Queue *queue) {
    if (isEmpty(queue)) {
        return ;
    }
    printf("Peak Value is : %d\n",queue->arr[queue->front]);
}

void printQueue(const struct Queue *queue) {
    if (isEmpty(queue)) {
        return;
    }
    printf("Queue Start");
    for (int i = 0; i < queue->size; i++) {
        printf("->%d",queue->arr[(queue->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    struct Queue *queue = initQueue();
    printf(
        "   ____\n"
        "  / __ \\\n"
        " | |  | |  _   _    ___   _   _    ___\n"
        " | |  | | | | | |  / _ \\ | | | |  / _ \\\n"
        " | |__| | | |_| | |  __/ | |_| | |  __/\n"
        "  \\___\\_\\  \\__,_|  \\___|  \\__,_|  \\___|\n"
    );
    while (1) {
        int input;
        printf("0.Enqueue\n1.Dequeue\n2.Peak\n3.isEmpty\n4.isFull\n5.Print\n6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&input);
        switch (input) {
            case 0:
                printf("Enter value to enqueue : ");
                scanf("%d",&input);
                enqueue(queue,input);
                break;
            case 1:
                printf("Removed: %d",dequeue(queue));
                break;
            case 2:
                peak(queue);
                break;
            case 3:
                printf("%s",isEmpty(queue) ? "True" : "False");
                break;
            case 4:
                printf("%s",isFull(queue) ? "True" : "False");
                break;
            case 5:
                printQueue(queue);
                break;
            default:
                free(queue);
                exit(0);
        }
    }
}



