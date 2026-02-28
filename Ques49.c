#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n;

    printf("enter number of nodes: ");
    scanf("%d", &n);

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

    int key;
    printf("enter key: ");
    scanf("%d", &key);

    int count = 0;
    temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("count: %d", count);

    return 0;
}