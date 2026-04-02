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

int cameras = 0;

int dfs(struct TreeNode* root) {
    if (!root) return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 2;
    }

    if (left == 2 || right == 2) {
        return 1;
    }

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == 0) cameras++;
    return cameras;
}

int main() {
    struct TreeNode* root = newNode(0);
    root->left = newNode(0);
    root->left->left = newNode(0);
    root->left->left->left = newNode(0);

    printf("%d\n", minCameraCover(root));

    return 0;
}