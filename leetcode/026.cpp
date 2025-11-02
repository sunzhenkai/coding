/**
 * @file   026.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sun Nov  2 11:57:08 AM CST 2025
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    std::unordered_set<int> flags;
    int l = 0;
    for (int j = 0; j < nums.size(); ++j) {
      auto exists = flags.find(nums[j]) != flags.end();
      if (!exists) {
        nums[l++] = nums[j];
        flags.insert(nums[j]);
      }
    }
    return l;
  }
};

int main() { return 0; }
