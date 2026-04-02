#include <stdio.h>
#include <stdlib.h>

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

void flatten(struct TreeNode* root) {
    if (!root) return;

    flatten(root->left);
    flatten(root->right);

    if (root->left) {
        struct TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        struct TreeNode* curr = root->right;
        while (curr->right) {
            curr = curr->right;
        }
        curr->right = temp;
    }
}

void printList(struct TreeNode* root) {
    while (root) {
        printf("%d ", root->val);
        root = root->right;
    }
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);
    printList(root);

    return 0;
}