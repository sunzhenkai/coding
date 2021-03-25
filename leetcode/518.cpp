/**
 * @file   518.cpp
 *
 * @brief  零钱兑换 II
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 17:32:51 CST 2021
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
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);

        for (int i = 1; i < amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i >= j)
                    dp[i] += dp[i - coins[j]];
            }
        }

        return dp[amount];
    }
};

int main() {
    return 0;
}
