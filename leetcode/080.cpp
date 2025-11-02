/**
 * @file   080.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sun Nov  2 12:01:31 PM CST 2025
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
    int l = 0;
    for (int r = 0, count = 0; r < nums.size(); ++r) {
      bool is_same = (r > 0 && nums[r] == nums[r - 1]);
      if (is_same)
        count++;
      else {
        count = 1;
      }
      if (count <= 2) {
        nums[l++] = nums[r];
      }
    }
    return l;
  }
};

int main() { return 0; }
