/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

bool isAnagram(char* s, char* t) {
    int ls = strlen(s);
    int lt = strlen(t);

    int sn[26] = {0};
    int tn[26] = {0};

    if (ls != lt) {
        return false;
    }

    for (int i = 0; i < ls; i++) {
        sn[s[i] - 'a']++;
        tn[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (sn[i] != tn[i]) {
            return false;
        }
    }

    return true;
}
