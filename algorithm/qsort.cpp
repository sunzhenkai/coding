#include <iostream>
#include <vector>

using namespace std;

void pv(vector<int> &nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

void qsort(vector<int> &nums, int l, int r) {
    if (l >= r) return;

    int pivot = nums[l], i = l, j = r;
    while (i < j) {
        while (j > i && nums[j] > pivot) j--;
        nums[i] = nums[j];

        while (i < j && nums[i] <= pivot) ++i;
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    qsort(nums, l, i-1);
    qsort(nums, i+1, r);
}


int main() {
    vector<int> v{3, 1, 2, 9, 0, 3, 5, 7, -1, 2};
    qsort(v, 0, v.size() - 1);
    pv(v);
    return 0;
}
