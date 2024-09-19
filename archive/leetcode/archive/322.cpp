/**
 * @file   322.cpp
 *
 * @brief  零钱兑换
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 17:20:24 CST 2021
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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i >= coins[j] && dp[i-coins[j]] != INT_MAX)
                    dp[j] = min(dp[j-coins[j]] + 1, dp[j]);
            }
        }
        return dp[amount];
    }
};

int main() {
    return 0;
}
