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

int length(struct node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void findIntersection(struct node* h1, struct node* h2) {

    int len1 = length(h1);
    int len2 = length(h2);

    int diff = abs(len1 - len2);

    if(len1 > len2) {
        for(int i = 0; i < diff; i++) h1 = h1->next;
    } else {
        for(int i = 0; i < diff; i++) h2 = h2->next;
    }

    // compare
    while(h1 != NULL && h2 != NULL) {
        if(h1->data == h2->data) {
            printf("%d", h1->data);
            return;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    printf("enter size list1: ");
    scanf("%d", &n);
    printf("enter elements: ");
    struct node* l1 = create(n);

    printf("enter size list2: ");
    scanf("%d", &m);
    printf("enter elements: ");
    struct node* l2 = create(m);

    findIntersection(l1, l2);

    return 0;
}