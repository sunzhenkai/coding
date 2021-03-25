/**
 * @file   416.cpp
 *
 * @brief  分割等和子集
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 16:14:04 CST 2021
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
    bool canPartition(vector<int>& nums) {
        int sm = 0, n = nums.size();
        if (n <= 1) return false;

        int mx = nums[0];
        for (int i = 0; i < n; ++i) {
            sm += nums[i];
        }
        if (sm & 1) return false;
        int target = sm / 2;
        if (mx > target) return false;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; ++i) dp[i][0] = true;

        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j < nums[i]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];
                }
            }
        }

        return dp[n-1][target];
    }
};

int main() {
    return 0;
}
