/**
 * @file   hashmap.cpp
 * @brief  
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sun 22 Sep 2024 09:19:49 AM CST
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class HashMap {
private:
    int _hash(int k) {
        return k % capacity;
    }

public:
    HashMap(int capacity) : capacity(capacity) {
        data.resize(capacity);
    }

    void put(int k, int value) {
        auto hk = _hash(k);
        for (auto &item: data[hk]) {
            if (item.first == k) {
                item.second = value;
                return;
            }
        }
        data[hk].push_back({k, value});
    }

    void get(int k, int &value) {
        auto hk = _hash(k);
        for (auto &item: data[hk]) {
            if (item.first == k) {
                value = item.second;
            }
        }
    }

    void remove(int k) {
        auto hk = _hash(k);
        for (auto it = data[hk].begin(); it != data[hk].end(); ++it) {
            if (it->first == k) {
                data[hk].erase(it);
                return;
            }
        }
    }

private:
    int capacity;
    std::vector<std::list<std::pair<int, int>>> data;
};

int main() {
    HashMap m(100);
    m.put(1, 1);
    m.put(2, 2);
    m.put(3, 3);
    m.put(4, 4);
    m.put(5, 5);

    int value;
    m.get(2, value);
    std::cout << "2: " << value << std::endl;
    m.get(4, value);
    std::cout << "4: " << value << std::endl;
    m.get(5, value);
    std::cout << "5: " << value << std::endl;
    return 0;
}
