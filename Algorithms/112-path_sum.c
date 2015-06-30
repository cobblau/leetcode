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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }

    if (!root->left && !root->right && root->val == sum) {
        return true;
    }

    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

bool hasPathSum2(struct TreeNode* root, int sum) {
    struct TreeNode *stack[2048], *p, *t;
    int pos = 0;

    if (root == NULL) {
        return false;
    }

    stack[pos++] = root;

    while (pos) {
        p = stack[pos-1];

        while (p->left) {
            stack[pos++] = p;
            p = p->left;
        }

        if (!p->right) {
            int cur = 0;
            for (int i = 0; i <= pos; i++) {
                cur += stack[i]->val;
            }

            if (cur == sum) {
                return true;
            }

            pos--;
        } else {
            stack[pos++] = p->right;
        }
    }

    return false;
}

int main()
{
    struct TreeNode *root = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    root->left = root->right = NULL;
    root->val = 1;

    printf("%d\n", hasPathSum2(root, 1));
}
