#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node* next;
};

int main() {
    int n;

    printf("enter number of terms: ");
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode;

    // create list
    printf("enter coef and exp:\n");
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        scanf("%d %d", &newnode->coef, &newnode->exp);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // display polynomial
    temp = head;

    while(temp != NULL) {
        if(temp->exp == 0) {
            printf("%d", temp->coef);
        }
        else if(temp->exp == 1) {
            printf("%dx", temp->coef);
        }
        else {
            printf("%dx^%d", temp->coef, temp->exp);
        }

        if(temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    return 0;
}