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

int isMirror(struct TreeNode* a, struct TreeNode* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    if (a->val != b->val) return 0;
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int isSymmetric(struct TreeNode* root) {
    if (!root) return 1;
    return isMirror(root, root);
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}