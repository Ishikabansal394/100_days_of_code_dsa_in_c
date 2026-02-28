#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n;

    printf("enter size: ");
    scanf("%d", &n);

    struct node *head = NULL, *temp, *newnode;

    printf("enter elements: ");
    for(int i = 0; i < n; i++) {

        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    struct node *slow = head;
    struct node *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("middle to end: ");
    while(slow != NULL) {
        printf("%d ", slow->data);
        slow = slow->next;
    }

    return 0;
}