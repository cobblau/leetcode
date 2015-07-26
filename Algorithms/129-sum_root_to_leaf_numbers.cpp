/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
 public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> canBreak(s.size() + 1, false);

        canBreak[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (!canBreak[i]) {
                continue;
            }

            for (int j = 1; j <= s.size() - i; j++) {
                if (canBreak[i + j]) {
                    continue;
                }

                if (wordDict.find(s.substr(i, j)) != wordDict.end()) {
                    canBreak[i + j] = true;
                }
            }
        }

        return canBreak[s.size()];
    }
};
