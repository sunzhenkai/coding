/**
 * @file   474.cpp
 *
 * @brief  一和零
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 16:36:36 CST 2021
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
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<int> zero(s, 0), one(s, 0);
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < strs[i].size(); ++j) {
                if (strs[i][j] == '0') ++zero[i];
                else ++one[i];
            }
        }

        vector<vector<vector<int>>> dp(s, vector<vector<int>>(m, vector<int>(n, 0)));

        for (int i = 1; i < s; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (zero[i] > j || one[i] > k) {
                        dp[i][j][k] = dp[i-1][j][k];
                    } else {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zero[i]][k-zero[i]]);
                    }
                }
            }
        }
        return dp[s-1][m][n];
    }
};

int main() {
    return 0;
}
