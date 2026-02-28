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

int isPalindrome(struct node* head) {

    int arr[1000], i = 0;

    struct node* temp = head;

    while(temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    int start = 0, end = i - 1;

    while(start < end) {
        if(arr[start] != arr[end]) return 0;
        start++;
        end--;
    }

    return 1;
}

int main() {
    int n;

    printf("enter size: ");
    scanf("%d", &n);

    printf("enter elements: ");
    struct node* head = create(n);

    if(isPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}