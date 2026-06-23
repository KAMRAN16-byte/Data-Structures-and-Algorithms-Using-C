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

struct node* init(const int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->next = NULL;
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

void reverse(struct Linked_List* LL) {
    struct node *next_node;
    struct node *previous_node = NULL;
    LL->tail = next_node = LL->head;
    while (next_node != NULL) {
        struct node *current = next_node;
        next_node = current->next;
        current->next = previous_node;
        previous_node = current;
    }
    LL->head = previous_node;
}

void remove_Duplicates(struct Linked_List* LL) {
    struct node* current = LL->head;
    while (current->next != NULL) {
        struct node* previous = current;
        struct node* runner = current->next;
        while (runner != NULL) {
            if (runner->data == current->data) {
                previous->next = runner->next;
                printf("\nRemoved duplicate element: %d\n", runner->data);
                free(runner);
                LL->size --;
            }
            else
                previous = runner;
            runner = previous->next;
        }
        current = current->next;
    }
    LL->tail = current;
}

void status(const struct Linked_List* LL) {
    if (LL->head == NULL) {
        return;
    }
    printf("\nLinked list status:\nHead: %d\nTail: %d\nSize: %d\n", LL->head->data, LL->tail->data, LL->size);
}

void print(const struct Linked_List LL) {
    const struct node* temp = LL.head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void partition_list(struct Linked_List* LL, const int value) {
    struct node *prev1,*prev2,*dummy1,*dummy2,*current;
    prev1 = dummy1 = init(0);
    prev2 = dummy2 = init(0);
    current = LL->head;
    while (current != NULL) {
        if (current->data < value) {
            prev1->next = current;
            prev1 = current;
            current = current->next;
            prev1->next = NULL;
        }
        else {
            prev2->next = current;
            prev2 = current;
            current = current->next;
            prev2->next = NULL;
        }
    }
    prev1->next = dummy2->next;
    LL->head = dummy1->next;
    free(dummy1);
    free(dummy2);
}

struct node* get(struct Linked_List* LL,int index) {
    if (index < 0) {
        index += LL->size;
    }
    if ( index > LL->size) {
        return NULL;
    }
    struct node* temp = LL->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

int set(struct Linked_List* LL,int index, const int data) {
    if (index < 0) {
        index += LL->size;
    }
    if ( index > LL->size) {
        return 0;
    }
    get(LL,index)->data = data;
    return 1;
}

struct node* middel_node(const struct Linked_List* LL) {
    struct node *fast,*slow;
    slow = fast = LL->head;
    while (fast != NULL) {
        if (fast->next == NULL)
            break;
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int has_loop(struct Linked_List* LL) {
    struct node *slow,*fast;
    slow = fast = LL->head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return 1;
    }
    return 0;
}

void swap_node(struct Linked_List* LL) {
    struct node *dummy,*prev,*current,*next;
    dummy = prev = init(0);
    dummy->next = LL->head;
    current = prev->next;
    while (current != NULL && current->next != NULL) {
        struct node* next_node = current->next;
        current->next = next_node->next;
        prev->next = next_node;
        next_node->next = current;
        prev = current;
        current = prev->next;
    }
    LL->head = dummy->next;
    LL->tail = prev;
    free(dummy);
}


int main() {
    struct Linked_List LL = Linked_List();
    append(&LL,1);
    append(&LL,2);

    print(LL);
    swap_node(&LL);
    status(&LL);
    print(LL);

    return 0;
}