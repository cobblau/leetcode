/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 */

/*
 * Hint:
 *   F[i][j] = min(F[i-1][j], F[i][j-1]) + grid[i][j]
 */
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int sum = 0;

    for (int i = 0; i < gridRowSize; i++) {
        grid[i][0] = sum + grid[i][0];
        sum = grid[i][0];
    }

    sum = 0;
    for (int i = 0; i < gridColSize; i++) {
        grid[0][i] = sum + grid[0][i];
        sum = grid[0][i];
    }

    for (int i = 1; i < gridRowSize; i++) {
        for (int j = 1; j < gridColSize; j++) {
            int min = grid[i][j-1] > grid[i-1][j] ? grid[i-1][j] : grid[i][j-1];
            grid[i][j] += min;
        }
    }

    return grid[gridRowSize-1][gridColSize-1];
}
