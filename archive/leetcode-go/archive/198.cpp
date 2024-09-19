/**
 * @file   198.cpp
 *
 * @brief  打家劫舍
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 11:53:08 CST 2021
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];

        int ans = max(dp[0][0], dp[0][1]);

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];

            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }

        return ans;
    }
};

int main() {
    return 0;
}
