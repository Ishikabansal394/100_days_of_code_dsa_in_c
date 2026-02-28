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

struct node* deleteKey(struct node* head, int key) {

    struct node *temp = head, *prev = NULL;

    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL) {
        prev->next = temp->next;
        free(temp);
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
    int n, key;

    printf("enter size: ");
    scanf("%d", &n);

    printf("enter elements: ");
    struct node* head = create(n);

    printf("enter key: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    printf("list: ");
    display(head);

    return 0;
}