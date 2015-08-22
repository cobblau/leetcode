/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */

#define DEBUG 1

/*
Description:

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#if DEBUG
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#endif

bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    if (len3 != (len1 + len2)) {
        return false;
    }

    bool dp[1024][1024] = {false};

    dp[0][0] = true;
    for (int i = 1; i <= len1; i++) {
        dp[i][0] = (dp[i-1][0] && (s1[i-1] == s3[i-1]));
    }

    for (int j = 1; j <= len2; j++) {
        dp[0][j] = (dp[0][j-1] && (s2[j-1] == s3[j-1]));
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
        }
    }

    return dp[len1][len2];
}

#if DEBUG
int main() {
    printf("%d\n", isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    printf("%d\n", isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    printf("%d\n", isInterleave("", "", ""));
    printf("%d\n", strlen(""));
}
#endif
