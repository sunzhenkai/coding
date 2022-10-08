/**
 * @file   213.cpp
 *
 * @brief  打家劫舍 II
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 11:59:00 CST 2021
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
        if (n == 1) {
            return nums[0]; 
        }


        int ans;
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        ans = dp[n-2];

        dp[0] = 0;
        dp[1] = nums[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return max(ans, dp[n-1]);
    }
};

int main() {
    return 0;
}
