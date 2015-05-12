/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */

int numTrees(int n) {
    int count[128] = {0};

    count[0] = count[1] = 1;
    count[2] = 2;

    for (int i = 3; i < 128; i++) {
        for (int j = 0; j < i; j++) {
            count[i] += count[j] * count[i - j - 1];
        }
    }

    return count[n];
}
