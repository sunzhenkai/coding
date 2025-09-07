#include <iostream>
#include <vector>

using namespace std;

template <typename T>
inline void PrintVector(vector<T> v) {
  for (auto e : v) {
    std::cout << e << " ";
  }
  std::cout << endl;
}
