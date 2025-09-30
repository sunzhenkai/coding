/**
 * @file   003.cpp
 * @brief  
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Wed Oct  1 05:55:15 AM CST 2025
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.empty()) return 0;

      bool flag[2 << 8];
      for (int i = 0; i < (2 << 8); ++i) flag[i] = false;
      flag[s[0]] = true;

      int result{1};
      for (int i = 1, j = 0; i < s.size(); ++i) {
        if (flag[s[i]]) {
          result = max(result, i - j);
          while (i > j) {
            if (s[i] != s[j])  {
              flag[s[j]] = false;
              j++;
            } else {
              j++;
              break;
            }
          }
        } else {
          result = max(result, i - j + 1);
          flag[s[i]] = true;
        }
      }
      return result;
    }
};

int main() { 
  std::string cs;
  Solution s;

  std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
  std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;
  std::cout << s.lengthOfLongestSubstring("bbbbbb") << std::endl;
  std::cout << s.lengthOfLongestSubstring("a") << std::endl;
  std::cout << s.lengthOfLongestSubstring("au") << std::endl;
  std::cout << s.lengthOfLongestSubstring(" ") << std::endl;
  return 0; 
}
