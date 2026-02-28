#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;

    printf("enter elements: ");
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

int hasLoop(struct node* head) {
    struct node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    struct node* head = create(n);

    struct node *temp = head;
    struct node *second = head->next;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = second; 
    if(hasLoop(head)) {
        printf("Loop detected");
    } else {
        printf("No loop");
    }

    return 0;
}