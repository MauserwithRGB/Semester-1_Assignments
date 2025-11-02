/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Max nodes is 100 per constraints
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    
    // Stack implementation using an array
    struct TreeNode* stack[100];
    int top = -1;
    struct TreeNode* curr = root;
    
    while (curr != NULL || top >= 0) {
        // Travel to the left-most node
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        
        // Pop the element
        curr = stack[top--];
        
        // Add to result (Inorder: Left -> Root -> Right)
        res[(*returnSize)++] = curr->val;
        
        // Move to the right subtree
        curr = curr->right;
    }
    
    return res;
}
