#include <iostream>
#include "utils.h"

using namespace std;

int main() {
    int ia[] = {1, 2, 3};
    vector<int> iv(ia, ia + sizeof(ia) / sizeof(int));
    reverse(iv, 0, 2);
    pV(iv);

    // int a[2<<8];
    // cout << (2<<8) << " " << sizeof(a);
    return 0;
}
