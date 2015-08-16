/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/

int judge(char *s1, int i1, int n1, char *s2, int i2, int n2) {
    if (n1 != n2) {
        return 0;
    }

    int sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    for (int i = i1; i < i1 + n1; i++) {
        sum1 += s1[i];
    }
    for (int i = i2; i < i2 + n2; i++) {
        sum2 += s2[i];
    }

    if (sum1 != sum2) {
        return 0;
    }

    if (n1 == 1) {
        return 1;
    }

    for (int n = 1; n < n1; n++) {
        if (judge(s1, i1, n, s2, i2, n) && judge(s1, i1+n, n1-n, s2, i2+1, n2-n)) {
            return 1;
        }

        if (judge(s1, i1, n, s2, i2+(n1-n), n) && judge(s1, i1+n, n1-n, s2, i2, n1-n)) {
            return 1;
        }
    }

    return 0;
}

int isScramble(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    return judge(s1, 0, len1, s2, 0, len2);
}

/*
int main() {
    printf("%d\n", isScramble("aa", "aa"));
    printf("%d\n", isScramble("ab", "ba"));
    printf("%d\n", isScramble("ab", "bb"));
    printf("%d\n", isScramble("abb", "bba"));
}
*/
