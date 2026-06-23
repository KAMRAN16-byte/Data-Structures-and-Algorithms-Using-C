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

int main() {
    struct DoubleLinkedList DLL = DoubleLinkedList();

    return 0;
}



