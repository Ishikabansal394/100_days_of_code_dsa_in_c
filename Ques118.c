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

struct TreeNode* buildHelper(int inorder[], int postorder[], int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd) return NULL;

    int val = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(val);

    if (inStart == inEnd) return root;

    int idx = findIndex(inorder, inStart, inEnd, val);

    root->right = buildHelper(inorder, postorder, idx + 1, inEnd, postIndex);
    root->left = buildHelper(inorder, postorder, inStart, idx - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildHelper(inorder, postorder, 0, n - 1, &postIndex);
}

void inorderPrint(struct TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    printf("%d ", root->val);
    inorderPrint(root->right);
}

int main() {
    int inorder[] = {4,2,5,1,3};
    int postorder[] = {4,5,2,3,1};
    int n = 5;

    struct TreeNode* root = buildTree(inorder, postorder, n);

    inorderPrint(root);

    return 0;
}