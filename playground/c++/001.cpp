#include <iostream>
#include <map>

using namespace std;

int main() {
    std::map<int, int> m = {
        {1, 2},
        {2, 3}
    };

    for (auto &entry : m) {
        std::cout << entry.first << " -> " << entry.second << std::endl;
    }
    return 0;
}
