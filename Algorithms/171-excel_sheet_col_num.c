/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
 */

int titleToNumber(char* s) {
    int n, cur, len;

    len = strlen(s);
    n = cur = 0;

    for (int i = 0; i < len; i++) {
        cur = (s[i] - 'A' + 1);
        n = n * 26 + cur;
    }

    return n;
}
