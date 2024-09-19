#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        vector<short> flag(256, 0);
        for (; r < s.length(); ++l, ++r) {
            for (; r < s.length() && !flag[s[r]]; ++r) {
                flag[s[r]] = 1;
            }

            res = max(res, r - l);
            if (r >= s.length()) {
                return res;
            }

            for (; s[l] != s[r] && l < r; ++l) {
                flag[s[l]] = 0;
            }
        }
        return res;
    }
};

int main() {
    string inp;
    Solution s;
    while (cin >> inp)
        cout << s.lengthOfLongestSubstring(inp) << endl;
    return 0;
}
