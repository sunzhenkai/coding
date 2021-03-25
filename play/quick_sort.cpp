/*
 * 快速排序的主要思想是通过划分将待排序的序列分成前后两部分，其中前一部分的数据都比后一部分的数据要小，然后再递归调用函数对两部分的序列分别进行快速排序，以此使整个序列达到有序。
 */
#include <iostream>

using namespace std;

void quickSort(int nums[], int l, int r) {
    int i = l, j = r;
    int pivot;

    if (i < j) {
        pivot = nums[i];
        while (i != j) {
            while (j > i && nums[j] > pivot) --j;
            nums[i] = nums[j];
            while (i < j && nums[i] < pivot) ++i;
            nums[j] = nums[i];
        }

        nums[i] = pivot;
        quicSort(nums, l, i-1);
        quicSort(nums, i+1, r);
    }
}

int main() {
    return 0;
}
