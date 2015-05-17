/**
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 * Hint: use stack
 */


/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2048    /.DocumentRevisions-V100   3
return [3,2,1].

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *stack[2048], *cur, *pre;
    int *arr, pos, n;

    arr = (int *)malloc(2048 * sizeof(int));

    pos = n = 0;
    pre = NULL;

    if (root) {
        stack[pos++] = root;
    }

    while (pos) {
        cur = stack[pos-1];

        if ((cur->left == NULL && cur->right == NULL) ||
            (pre && (pre == cur->left || pre == cur->right)))
            {
                arr[n++] = cur->val;
                pos--;     // pop from stack
                pre = cur;
            } else {
            if (cur->right) {
                stack[pos++] = cur->right;  // push right child
            }

            if (cur->left) {
                stack[pos++] = cur->left;   // push left child
            }
        }
    }

    *returnSize = n;
    return arr;
}
