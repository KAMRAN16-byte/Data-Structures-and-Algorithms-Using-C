//
// Created by Development on 20-06-2026.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct Linked_List {
    struct node* head;
    struct node* tail;
    int size;
};

struct Linked_List Linked_List() {
    const struct Linked_List temp = {.head = NULL, .tail = NULL, .size = 0};
    return temp;
}

struct node* init(int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    return temp;
}

int append(struct Linked_List* LL, const int data) {
    struct node* temp = init(data);
    if (LL->head == NULL) {
        LL->head = LL->tail = temp;
    }
    else {
        LL->tail->next = temp;
        LL->tail = temp;
    }
    temp->next = NULL;
    LL->size ++;
    return 1;
}

int prepend(struct Linked_List* LL, const int data) {
    struct node* temp = init(data);
    temp->next = LL->head;
    if (LL->head == NULL) {
        LL->head = LL->tail = temp;
    }
    else {
        LL->head = temp;
    }
    LL->size ++;
    return 1;
}

struct node* pop_first(struct Linked_List* LL) {
    struct node* temp = LL->head;
    if (LL->head == NULL) {
        return NULL;
    }
    if (LL->head == LL->tail) {
        LL->head = LL->tail = NULL;
    }
    else {
        LL->head = LL->head->next;
    }
    LL->size --;
    return temp;
}

struct node* pop(struct Linked_List* LL) {
    struct node* temp = LL->tail;
    if (LL->head == NULL) {
        return NULL;
    }
    if (LL->head == LL->tail) {
        LL->head = LL->tail = NULL;
    }
    else {
        struct node* temp_ = LL->head;
        while (temp_->next != LL->tail) {
            temp_ = temp_->next;
        }
        LL->tail = temp_;
        LL->tail->next = NULL;
    }
    LL->size --;
    return temp;
}

void print(const struct Linked_List LL) {
    const struct node* temp = LL.head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    setbuf(stdout, NULL);
    struct Linked_List LL = Linked_List();
    append(&LL, 10);
    append(&LL, 20);
    pop(&LL);
    prepend(&LL, 80);
    append(&LL, 30);
    pop_first(&LL);
    prepend(&LL, 90);

    print(LL);

    return 0;
}
