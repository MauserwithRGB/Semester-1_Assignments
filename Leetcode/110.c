/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
#include <stdlib.h>

int checkHeight(struct TreeNode* root) {
    if (root == NULL) return 0;

    int leftH = checkHeight(root->left);
    if (leftH == -1) return -1; // Propagate imbalance from left

    int rightH = checkHeight(root->right);
    if (rightH == -1) return -1; // Propagate imbalance from right

    if (abs(leftH - rightH) > 1) return -1; // Current node is unbalanced

    return (leftH > rightH ? leftH : rightH) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}
