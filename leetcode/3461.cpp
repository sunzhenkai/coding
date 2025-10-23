/**
 * @file   3461.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Thu Oct 23 10:16:27 AM CST 2025
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
  bool hasSameDigits(string s) {
    if (s.size() <= 1) return false;
    for (int i = 0; i < s.size(); ++i) s[i] -= '0';
    while (s.size() > 2) {
      for (int i = 0; i < s.size() - 1; i++) {
        s[i] = (s[i] + s[i + 1]) % 10;
      }
      s.resize(s.size() - 1);
    }
    return s[0] == s[1];
  }
};

int main() {
  std::string s;
  Solution sl;

  s = "34789";
  std::cout << sl.hasSameDigits(s) << std::endl;
  return 0;
}
