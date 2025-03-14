/**
 * @file   009.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat 15 Mar 2025 04:27:19 CST
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    short digitals[32];
    short idx(0);
    while (x > 0) {
      digitals[idx++] = x % 10;
      x /= 10;
    }
    for (short i = 0; i < idx / 2; ++i) {
      if (digitals[i] != digitals[idx - i - 1]) return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  std::cout << s.isPalindrome(121) << std::endl;
  std::cout << s.isPalindrome(10) << std::endl;
  std::cout << s.isPalindrome(0) << std::endl;
  std::cout << s.isPalindrome(1221) << std::endl;
  std::cout << s.isPalindrome(-121) << std::endl;
  return 0;
}
