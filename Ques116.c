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

int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd) return NULL;

    int val = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = newNode(val);

    if (inStart == inEnd) return root;

    int idx = findIndex(inorder, inStart, inEnd, val);

    root->left = buildTreeHelper(preorder, inorder, inStart, idx - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, idx + 1, inEnd, preIndex);

    return root;
}

struct TreeNode* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, n - 1, &preIndex);
}

void preorderPrint(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    int preorder[] = {1,2,4,5,3};
    int inorder[] = {4,2,5,1,3};
    int n = 5;

    struct TreeNode* root = buildTree(preorder, inorder, n);

    preorderPrint(root);

    return 0;
}