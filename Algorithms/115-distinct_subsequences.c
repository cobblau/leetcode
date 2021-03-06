/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

int numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    int **dp;
    dp = (int **) malloc((m+1) * sizeof(int *));

    for (int i = 0; i < m + 1; i++) {
        dp[i] = (int *) malloc((n+1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ret = dp[m][n];
    for (int i = 0; i < m + 1; i++) {
        free(dp[i]);
    }
    free(dp);

    return ret;
}
