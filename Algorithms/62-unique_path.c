/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
 */

int uniquePaths(int m, int n) {
    int i, j;
    int sol[100][100] = {0};

    for (i = 0; i < m; i++) {
        sol[i][0] = 1;
    }

    for (j = 0; j < n; j++) {
        sol[0][j] = 1;
    }

    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            sol[i][j] = sol[i-1][j] + sol[i][j-1];
        }
    }

    return sol[m-1][n-1];
}
