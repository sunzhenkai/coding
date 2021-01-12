#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {        
        string ans = "";
        int n= s.length();
        bool dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));

        if (n <= 1) {
            return s;
        }
        
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + 1 < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = true;
                } else if (l == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                }

                if (dp[i][j] && l + 1 > ans.length()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    string inp;
    while (cin >> inp) {
        cout << s.longestPalindrome(inp) << endl;
    }
    return 0;
}
