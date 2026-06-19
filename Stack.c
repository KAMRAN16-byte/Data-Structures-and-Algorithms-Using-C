#include <stdio.h>
#include <stdlib.h>
#define max 10

int top = -1;
int arr[max];

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == max - 1;
}

int push(int data) {
    if (isFull()) {
        printf("\nStack Overflow\n");
        return 0;
    }
    arr[++top] = data;
    return 1;
}

int pop() {
    if (isEmpty()) {
        printf("\nStack Underflow\n");
        return 0;
    }
    return arr[top--];
}

void print() {
    if (isEmpty()) return;
    printf("\nStack : \n");
    for (int* index = &arr[top]; index >= arr; index--) {
        printf("%d\n", *index);
    }
}

void peak() {
    if (top == -1) {
        return;
    }
    printf("\n%d\n", arr[top]);

}
int main() {
    setbuf(stdout, NULL);
    printf("  ____    _                    _\n");
    printf(" / ___|  | |_    __ _    ___  | | __\n");
    printf(" \\___ \\  | __|  / _` |  / __| | |/ /\n");
    printf("  ___) | | |_  | (_| | | (__  |   <\n");
    printf(" |____/   \\__|  \\__,_|  \\___| |_|\\_\\\n");

    while (1) {
        printf("0. Push\n1. Pop\n2. Peak\n3. Print\n4. Exit\n");
        printf("Enter the Option: ");

        int input;
        scanf("%d", &input);
        switch (input) {
            case 0:
                printf("\nEnter the value to be pushed: ");
                scanf("%d", &input);
                printf("\n");
                push(input);
                break;
            case 1:
                pop();
                break;
            case 2:
                peak();
                break;
            case 3:
                print();
                break;
            default:
                exit(0);
        }

    }

}