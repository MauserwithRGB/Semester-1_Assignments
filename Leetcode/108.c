/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

struct TreeNode* buildBST(int* nums, int left, int right) {
    if (left > right) return NULL;
    
    // Pick middle element to maintain balance
    int mid = left + (right - left) / 2;
    
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    
    // Recursively build left and right subtrees
    node->left = buildBST(nums, left, mid - 1);
    node->right = buildBST(nums, mid + 1, right);
    
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildBST(nums, 0, numsSize - 1);
}
