/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

//#include <stdio.h>
//#include <string.h>

int min3(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    } else {
        return b < c ? b : c;
    }
}

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int d[256][256];

    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int t = 1;
            if (word1[i-1] == word2[j-1]) {
                t = 0;
            }

            d[i][j] = min3(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + t);
            printf("%d %d %d\n", i, j, d[i][j]);
        }
    }

    return d[len1][len2];
}

/*
int main() {
    printf("%d\n", minDistance("a", "a"));
    printf("%d\n", minDistance("a", "b"));
    printf("%d\n", minDistance("a", "ab"));
    printf("%d\n", minDistance("a", "abc"));
}
*/
