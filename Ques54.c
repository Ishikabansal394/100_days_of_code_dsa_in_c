#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int removeCycle(struct node* head) {

    struct node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {

            slow = head;

            if(slow == fast) {
                while(fast->next != slow) {
                    fast = fast->next;
                }
                fast->next = NULL;
                return 1;
            }

            while(slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = NULL;  
            return 1;
        }
    }

    return 0; 
}

int main() {

    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *n2 = (struct node*)malloc(sizeof(struct node));
    struct node *n3 = (struct node*)malloc(sizeof(struct node));
    struct node *n4 = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; 
    if(removeCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}