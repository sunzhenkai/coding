/**
 * @file   169.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat Nov  8 08:45:55 AM CST 2025
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
  int majorityElement(vector<int>& nums) {
    int num = nums[0], count{1};
    for (int i = 1; i < nums.size(); ++i) {
      if (num == nums[i]) {
        count++;
      } else if (count > 0) {
        count--;
      }

      if (count <= 0) {
        num = nums[i];
        count = 1;
      }
    }
    return num;
  }
};

int main() { return 0; }
