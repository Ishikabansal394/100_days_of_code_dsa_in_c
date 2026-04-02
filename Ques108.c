#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void zigzagLevelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int temp[MAX];

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            int idx = leftToRight ? i : (size - 1 - i);
            temp[idx] = curr->val;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", temp[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    zigzagLevelOrder(root);

    return 0;
}