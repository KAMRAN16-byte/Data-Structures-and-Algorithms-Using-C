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


int prepend(struct DoubleLinkedList* DLL, const int data) {
    struct node* new_node = init(data);
    if (DLL->head == NULL) {
        new_node->next = NULL;
        DLL->head = DLL->tail = new_node;
    }
    else {
        new_node->next = DLL->head;
        DLL->head->prev = new_node;
        DLL->head = new_node;
    }
    new_node->prev = NULL;
    DLL->size ++;
    return 1;
}

int insert_at(struct DoubleLinkedList* DLL, const int data, const int index) {
    if (index < 0 || index > DLL->size) {
        return 0;
    }
    if (index == 0) {
        return prepend(DLL,data);
    }
    if (index == DLL->size) {
        append(DLL,data);
    }
    struct node* new_node = init(data);
    struct node* temp = DLL->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    (temp->prev)->next = new_node;
    new_node->prev = temp->prev;
    new_node->next = temp;
    temp->prev = new_node;
    return 1;
}

void print(const struct DoubleLinkedList DLL) {
    const struct node* temp = DLL.head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void status(const struct DoubleLinkedList* DLL) {
    if (DLL->head == NULL) {
        return;
    }
    printf("");
}

int main() {
    struct DoubleLinkedList DLL = DoubleLinkedList();
    append(&DLL,1);
    append(&DLL,2);
    append(&DLL,3);
    append(&DLL,4);
    append(&DLL,5);
    insert_at(&DLL,6,2);
    pop_first(&DLL);
    print(DLL);
    return 0;
}



