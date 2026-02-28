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

    
    temp->next = head;
    printf("list: ");
    struct node* curr = head;

    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while(curr != head);

    return 0;
}