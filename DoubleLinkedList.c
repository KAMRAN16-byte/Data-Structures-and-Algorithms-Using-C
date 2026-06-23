//
// Created by Development on 23-06-2026.
//
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct DoubleLinkedList {
    struct node *head;
    struct node *tail;
    int size;
};

struct DoubleLinkedList DoubleLinkedList() {
    const struct DoubleLinkedList temp = {.head = NULL, .tail = NULL,.size = 0};
    return temp;
}

struct node* init(const int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    return new_node;
}

int append(struct DoubleLinkedList* DLL, const int data) {
    struct node* new_node = init(data);
    if (DLL->head == NULL) {
        new_node->prev = NULL;
        DLL->head = DLL->tail = new_node;
    }
    else {
        new_node->prev = DLL->tail;
        DLL->tail->next = new_node;
        DLL->tail = new_node;
    }
    new_node->next= NULL;
    DLL->size ++;
    return 1;
}

struct node* pop(struct DoubleLinkedList* DLL) {
    struct node* temp = DLL->tail;
    if (DLL->head == DLL->tail) {
        DLL->head = DLL->tail = NULL;
        DLL->size = 0;
    }
    else {
        DLL->tail = DLL->tail->prev;
        (DLL->tail->next)->prev = NULL;
        DLL->tail->next = NULL;
        DLL->size--;
    }
    return temp;
}

void print(const struct DoubleLinkedList DLL) {
    const struct node* temp = DLL.head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct DoubleLinkedList DLL = DoubleLinkedList();
    append(&DLL,1);
    append(&DLL,2);
    append(&DLL,3);
    append(&DLL,4);
    pop(&DLL);
    append(&DLL,5);
    print(DLL);
    return 0;
}



