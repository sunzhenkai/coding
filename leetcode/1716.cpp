/**
 * @file   1716.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat Oct 25 10:54:53 AM CST 2025
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
  int totalMoney(int n) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
      result += (1 + i / 7) + i % 7;
    }
    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.totalMoney(1) << std::endl;
  std::cout << s.totalMoney(4) << std::endl;
  std::cout << s.totalMoney(10) << std::endl;
  std::cout << s.totalMoney(20) << std::endl;
  return 0;
}
