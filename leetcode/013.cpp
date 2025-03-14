/**
 * @file   013.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat 15 Mar 2025 04:39:27 CST
 */

#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "/Users/wii/workspace/public/coding/template/leetcode.h"
#include "/Users/wii/workspace/public/coding/template/utils.h"

using namespace std;

using MapType = std::unordered_map<short, short>;
class Solution {
  static MapType kM;

 public:
  int romanToInt(string s) {
    if (s.empty()) return 0;
    int result(kM[s[0]]);
    for (size_t i = 1, latest = result; i < s.size(); ++i) {
      short current = kM[s[i]];
      if (current > latest) {
        result -= latest + latest;
      }
      result += current;
      latest = current;
    }
    return result;
  }
};

MapType Solution::kM = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

int main() {
  Solution s;
  std::cout << s.romanToInt("IV") << std::endl;
  std::cout << s.romanToInt("III") << std::endl;
  std::cout << s.romanToInt("LVIII") << std::endl;
  std::cout << s.romanToInt("MCMXCIV") << std::endl;
  return 0;
}
