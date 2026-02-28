#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* create(int n) {
    struct node *head = NULL, *temp, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* merge(struct node* h1, struct node* h2) {

    struct node *head = NULL, *temp = NULL;

    while(h1 != NULL && h2 != NULL) {

        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;

        if(h1->data < h2->data) {
            newnode->data = h1->data;
            h1 = h1->next;
        } else {
            newnode->data = h2->data;
            h2 = h2->next;
        }

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // remaining elements
    while(h1 != NULL) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = h1->data;
        newnode->next = NULL;

        if(head == NULL) head = newnode;
        else temp->next = newnode;

        temp = newnode;
        h1 = h1->next;
    }

    while(h2 != NULL) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = h2->data;
        newnode->next = NULL;

        if(head == NULL) head = newnode;
        else temp->next = newnode;

        temp = newnode;
        h2 = h2->next;
    }

    return head;
}

void display(struct node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    printf("enter size of list1: ");
    scanf("%d", &n);
    printf("enter elements: ");
    struct node* l1 = create(n);

    printf("enter size of list2: ");
    scanf("%d", &m);
    printf("enter elements: ");
    struct node* l2 = create(m);

    struct node* result = merge(l1, l2);

    printf("merged: ");
    display(result);

    return 0;
}