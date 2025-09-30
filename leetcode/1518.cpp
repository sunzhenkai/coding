/**
 * @file   1518.cpp
 * @brief  
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Wed Oct  1 05:30:47 AM CST 2025
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      if (numExchange == 1) return numBottles;
      int result = numBottles;
      while (numBottles > 0) {
        int cur = numBottles / numExchange;
        result += cur;
        if (cur == 0) break;
        numBottles = cur + numBottles % numExchange;
      }
      return result;
    }
};

int main() { return 0; }
