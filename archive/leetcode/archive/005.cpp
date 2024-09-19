/**
 * @file   005.cpp
 *
 * @brief  最长回文子串
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 11:25:23 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l+1);
                }
            }
        } 
        return ans;
    }
};

int main() {
    return 0;
}
