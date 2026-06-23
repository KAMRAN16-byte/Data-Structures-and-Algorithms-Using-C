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
    struct node *dummy,*prev,*current,*next_node;
    dummy = prev = init(0);
    dummy->next = LL->head;
    current = prev->next;
    while (current != NULL && current->next != NULL) {
        next_node = current->next;
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

void reverse_range(struct Linked_List* LL, int start, int end) {
    if (start > LL->size || end > LL->size-1)
        return;
    struct node *prev,*dummy,*current,*to_move;
    dummy = init(0);
    dummy->next = LL->head;
    current = prev = dummy;
    for (int i = 0; i < start; i++) {
        prev=prev->next;
    }
    current = prev->next;
    for (int i = 0; i < end-start; i++) { //end is included
        to_move = current->next;
        current->next = to_move->next;
        to_move->next = prev->next;
        prev->next = to_move;
    }
    LL->head = dummy->next;
    LL->tail = NULL;
    free(dummy);
}

int insert_at(struct Linked_List* LL, const int index, const int data) {
    if (index < 0 || index > LL->size) {
        return -1;
    }
    if (index == 0) {
        return prepend(LL,data);
    }
    if (index == LL->size) {
        return append(LL,data);
    }
    struct node* new_node = init(data);
    struct node* prev_node = get(LL,index-1);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    LL->size++;
    return 1;
}

struct node* remove_at(struct Linked_List* LL, const int index) {
    if (index < 0 || index >= LL->size) {
        return NULL;
    }
    if (index == 0) {
        return pop_first(LL);
    }
    if (index == LL->size-1) {
        return pop(LL);
    }
    struct node* prev_node = get(LL,index-1);
    struct node* to_remove = prev_node->next;
    prev_node->next = to_remove->next;
    to_remove->next = NULL;
    LL->size--;
    return to_remove;
}

int main() {
    struct Linked_List LL = Linked_List();
    append(&LL,1);
    append(&LL,2);
    append(&LL,3);
    append(&LL,4);
    append(&LL,5);
    append(&LL,6);
    print(LL);
    remove_at(&LL,LL.size-2);
    status(&LL);
    print(LL);
    return 0;
}