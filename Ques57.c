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

// find length
int length(struct node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// rotate right
struct node* rotate(struct node* head, int k) {

    if(head == NULL || head->next == NULL) return head;

    int n = length(head);
    k = k % n;

    if(k == 0) return head;

    struct node* temp = head;

    // go to last node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // make circular
    temp->next = head;

    int steps = n - k;
    temp = head;

    // move to (n-k)th node
    for(int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // new head
    struct node* newHead = temp->next;

    // break link
    temp->next = NULL;

    return newHead;
}

// display
void display(struct node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    printf("enter size: ");
    scanf("%d", &n);

    printf("enter elements: ");
    struct node* head = create(n);

    printf("enter k: ");
    scanf("%d", &k);

    head = rotate(head, k);

    printf("rotated: ");
    display(head);

    return 0;
}