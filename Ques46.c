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

int hasCycle(struct node* head) {
    struct node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;
    }
    return 0;
}

int main() {
    int n;

    printf("enter size: ");
    scanf("%d", &n);

    printf("enter elements: ");
    struct node* head = create(n);
    if(hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}