#include <iostream>
#include "utils.h"

using namespace std;

int main() {
    // vector<int> iv{1, 2, 3};
    vector<int> iv(3, 1);
    swapT(iv[0], iv[2]);
    pV(iv);
    // int ia[] = {1, 2, 3};
    // vector<int> iv(ia, ia + sizeof(ia) / sizeof(int));
    // swapT(iv[0], iv[2]);
    // pV(iv);

    // int a[2<<8];
    // cout << (2<<8) << " " << sizeof(a);
    return 0;
}
