/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.

*/

int uniquePathsWithObstacles(int** obstacleGrid, int m, int n) {
    int i, j;
    int path[100][100] = {0};

    for (i = 0; i < m; i++) {
        path[i][0] = 1;

        if (obstacleGrid[i][0] == 1) {
            path[i][0] = 0;
            continue;
        }

        if (i > 0 && path[i-1][0] == 0) {
            path[i][0] = 0;
        }
    }

    for (j = 0; j < n; j++) {
        path[0][j] = 1;

        if (obstacleGrid[0][j] == 1) {
            path[0][j] = 0;
            continue;
        }

        if (j > 0 && path[0][j-1] == 0) {
            path[0][j] = 0;
        }
    }

    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                path[i][j] = 0;
                continue;
            }

            path[i][j] = path[i-1][j] + path[i][j-1];
        }
    }

    return path[m-1][n-1];
}
