/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /.DocumentRevisions-V100   3
return [1,2,3].

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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *p;
    struct TreeNode *stack[4096];
    int *arr, m, pos;

    arr = (int *) malloc(4096 * sizeof(int));
    //memset(arr, 0, *returnSize);

    pos = m = 0;
    if (root) {
        stack[pos++] = root;
    }

    while (pos) {
        p = stack[--pos];
        arr[m++] = p->val;

        if (p->right) {
            stack[pos++] = p->right;
        }

        if (p->left) {
            stack[pos++] = p->left;
        }
    }

    *returnSize = m;
    return arr;
}
