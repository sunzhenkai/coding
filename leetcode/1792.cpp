/**
 * @file   1792.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Mon Sep  1 07:28:17 PM CST 2025
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

/*
 * 思路
 * 使用优先队列，将最大增益的班级放在 root
 * 增益计算: (pass+1)/(total+1) - pass/total
 * */

class Solution {
  struct ClassPassInfo {
    double pass, total;
    double gain() const {
      return (pass + 1.0) / (total + 1.0) - (pass / total);
    }
    bool operator<(const ClassPassInfo& cpi) const {
      return gain() < cpi.gain();
    }
  };

 public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    if (classes.empty()) return 0;

    std::priority_queue<ClassPassInfo> q;
    for (auto& cls : classes) {
      q.push(ClassPassInfo{double(cls[0]), double(cls[1])});
    }

    for (int i = 0; i < extraStudents; ++i) {
      auto e = q.top();
      q.pop();
      e.pass += 1;
      e.total += 1;
      q.push(e);
    }

    double result = 0.0;
    while (!q.empty()) {
      auto e = q.top();
      q.pop();
      result += e.pass / e.total;
    }
    return result / classes.size();
  }
};

int main() {
  std::vector<vector<int>> classes{{1, 2}, {3, 5}, {2, 2}};
  Solution s;
  auto r = s.maxAverageRatio(classes, 2);
  std::cout << "RESULT: " << r << std::endl;
  return 0;
}
