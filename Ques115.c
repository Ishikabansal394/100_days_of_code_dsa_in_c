#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val) return i;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd) return NULL;

    int val = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(val);

    if (inStart == inEnd) return root;

    int idx = findIndex(inorder, inStart, inEnd, val);

    root->left = build(preorder, inorder, inStart, idx - 1, preIndex);
    root->right = build(preorder, inorder, idx + 1, inEnd, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}