/*
 * 快速排序的主要思想是通过划分将待排序的序列分成前后两部分，其中前一部分的数据都比后一部分的数据要小，然后再递归调用函数对两部分的序列分别进行快速排序，以此使整个序列达到有序。
 */
#include <iostream>

using namespace std;

// 对 nums[left, right] 排序
void QuickSort(int nums[], int left, int right) {
    if (left >= right) return;
    int cur_l = left, cur_r = right;
    while (cur_l < cur_r) {
        int pivot = nums[cur_l];
        while (cur_l != cur_r) {
            while (cur_r > cur_l && nums[cur_r] > pivot) --cur_r;
            nums[cur_l] = nums[cur_r];
            while (cur_r > cur_l && nums[cur_l] < pivot) ++cur_l;
            nums[cur_r] = nums[cur_l];
        }
        nums[cur_l] = pivot;
    }
    QuickSort(nums, left, cur_l - 1);
    QuickSort(nums, cur_r + 1, right);
}

void print_array(int nums[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int nums[5] = {2, 1, 5, 4, 3};
    QuickSort(nums, 0, 4);
    print_array(nums, 5);
    return 0;
}
