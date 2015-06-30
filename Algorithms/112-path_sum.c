/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
*/

/* recursion version */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }

    if (!root->left && !root->right && root->val == sum) {
        return true;
    }

    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

/* iterative version */
bool hasPathSum2(struct TreeNode* root, int sum) {
    struct TreeNode *stack[2048];
    struct TreeNode *p, *pre;
    int pos = 0;

    if (root == NULL) {
        return false;
    }

    pre = p = NULL;
    p = root;

    while (p != NULL || pos) {
        while (p) {
            stack[pos++] = p;
            p = p->left;
        }

        p = stack[pos-1];

        if (!p->left && !p->right) {
            int cur = 0;
            for (int i = 0; i < pos; i++) {
                cur += stack[i]->val;
            }

            if (cur == sum) {
                return true;
            }
        }

        if (!p->right || pre == p->right) {
            pre = p;
            pos--;
            p = NULL;
        } else {
            p = p->right;
        }
    }

    return false;
}

/*
int main()
{
    struct TreeNode *root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left = root->right = NULL;
    root->val = 1;

    struct TreeNode *p = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    p->left = p->right = NULL;
    p->val = 2;

    root->left = p;
    printf("%d\n", hasPathSum2(root, 1));
}
*/
