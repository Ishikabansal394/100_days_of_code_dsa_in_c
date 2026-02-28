#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* head = NULL;
int size = 0;

int get(int index) {
    if(index < 0 || index >= size) return -1;

    struct node* temp = head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->val;
}

void addAtHead(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = head;
    head = newnode;
    size++;
}

void addAtTail(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    size++;
}

void addAtIndex(int index, int val) {
    if(index > size) return;

    if(index == 0) {
        addAtHead(val);
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = val;

    struct node* temp = head;
    for(int i = 0; i < index-1; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    size++;
}

void deleteAtIndex(int index) {
    if(index < 0 || index >= size) return;

    struct node* temp = head;

    if(index == 0) {
        head = temp->next;
        free(temp);
        size--;
        return;
    }

    struct node* prev = NULL;
    for(int i = 0; i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
    size--;
}

void display() {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    addAtHead(10);
    addAtTail(20);
    addAtTail(30);
    addAtIndex(1, 15);

    display();  

    printf("get(2): %d\n", get(2)); 

    deleteAtIndex(1);
    display();  

    return 0;
}