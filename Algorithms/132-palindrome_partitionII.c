/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

int minCut(char* s) {
    // isPd[i][j]: is s[i...j] is palindrome
    bool isPd[2048][2048] = {false};

    // dp[i]: the minimum cuts of s[i...n-1]. the initial number is n-i-1
    int dp[2048];

    if (s == NULL || strlen(s) <= 1) {
        return 0;
    }

    int n = strlen(s);
    for (int i = n-1; i >= 0; i--) {
        dp[i] = n-i-1;

        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i < 2 || isPd[i+1][j-1])) {
                isPd[i][j] = true;

                if (j == n-1) {
                    dp[i] = 0;
                } else if (dp[j+1] + 1 < dp[i]){
                    dp[i] = dp[j+1] + 1;
                }
            }
        }
    }

    return dp[0];
}
