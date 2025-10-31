/**
 * @file   27.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat Nov  1 07:19:32 AM CST 2025
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
  int removeElement(vector<int>& nums, int val) {
    int l = 0;
    for (int r = 0; r < nums.size(); ++r) {
      if (nums[r] != val) nums[l++] = nums[r];
    }
    return l;
  }
};

int main() { return 0; }
