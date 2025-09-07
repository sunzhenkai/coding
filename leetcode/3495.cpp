/**
 * @file   3495.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat Sep  6 14:53:18 CST 2025
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

/*
 * 1 1 1 1, 2 2 2 2, 3 3 3 3, ...., n n n n
 * 1 * 4, 2 * 4, 3 * 4, ... n * 4
 * 4^0, ... 4^m
 * */

class Solution {
 public:
  int index(int n) {
    int result = 0;
    while (n > 0) {
      n /= 4;
      ++result;
    }
    return result;
  }

  long long pow(int n) {
    if (n <= 0) return 0;
    long long result = 1;
    for (auto i = 0; i < n; ++i) {
      result *= 4;
    }
    return result;
  }

  long long minOperation(vector<int> &query) {
    int from = index(query[0]);
    int to = index(query[1]);
    std::vector<int> operation_array;
    int latest = query[0];
    std::cout << "> " << from << " " << to << std::endl;
    for (int i = from; i <= to; ++i) {
      long long cur = pow(i);
      if (i == to) {
        operation_array.emplace_back((query[1] - latest) * i);
      } else {
        operation_array.emplace_back((cur - latest) * i);
      }
    }

    PrintVector(operation_array);
    return 0;
  }

  long long minOperations(vector<vector<int>> &queries) {
    long long result{0};
    for (auto &query : queries) {
      result += minOperation(query);
    }
    return result;
  }
};

int main() {
  std::vector<std::vector<int>> vvi{{1, 2}, {2, 4}};
  Solution s;
  std::cout << s.minOperations(vvi) << std::endl;
  return 0;
}
