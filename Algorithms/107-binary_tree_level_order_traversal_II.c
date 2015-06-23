/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    struct TreeNode* queue[100000], *p;
    int **arr, len;
    int *colSizes, size;
    int *subarr, pos;
    int head, tail, boundary;

    if (root == NULL) {
        *returnSize = 0;
        *columnSizes = NULL;
        return NULL;
    }

    arr = (int **) malloc(sizeof(int *) * 1024);
    len = 0;

    colSizes = (int *) malloc(sizeof(int) * 1024);
    head = tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        boundary = tail;

        size = boundary - head;

        subarr = (int *) malloc(sizeof(int) * size);
        pos = 0;

        while (head < boundary) {
            p = queue[head++];

            if (p->left) {
                queue[tail++] = p->left;
            }

            if (p->right) {
                queue[tail++] = p->right;
            }

            subarr[pos++] = p->val;
        }
        colSizes[len] = size;
        arr[len] = subarr;
        len++;
    }

    for (int i = 0; i < len / 2; i++) {
        int *t = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = t;

        int tmp = colSizes[i];
        colSizes[i] = colSizes[len - i - 1];
        colSizes[len - i - 1] = tmp;
    }

    *returnSize = len;
    *columnSizes = colSizes;
    return arr;
}

/*
int main()
{
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = root->right = NULL;

    int **arr, *colSize, size;

    arr = levelOrderBottom(root, &colSize, &size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < colSize[i]; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}
*/
