#include <iostream>
#include <memory>
#include <mutex>
#include <shared_mutex>

template <typename T>
class Singleton {
 public:
  T &Instance() {
    static T t;
    return t;
  }
};

template <typename T>
class SafeSingleton {
 public:
  T &Instance() {
    // 先判断有没有初始化
    if (obj) {
      return *obj;
    }

    std::unique_lock lock(mtx);
    // 如果其他线程创建好
    if (obj) {
      return *obj;
    }
    obj = std::make_shared<T>();
    return *obj;
  }

 private:
  std::shared_mutex mtx;
  std::shared_ptr<T> obj;
};

class A : public SafeSingleton<A> {};

int main() { return 0; }
