/**
 * @file   279.cpp
 *
 * @brief  完全平方数
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 15:41:50 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> seq;
        vector<int> dp(n + 1, INT_MAX - 1);
        for (int i = 1; i <= sqrt(n); ++i) {
            seq.push_back(i * i);
        }

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < seq.size() && i >= seq[j]; ++j) {
                dp[i] = min(dp[i], dp[i-seq[j]] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    return 0;
}
