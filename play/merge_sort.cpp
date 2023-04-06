#include <iostream>
#include "vector"

void merge(int nums[], int left, int mid, int right) {
    int backup[right - left + 1]; // 备份 nums[left, right]
    // cur_l: backup 左指针, cur_r backup 右指针, cur nums 当前指针
    int cur_l = 0, cur_r = mid - left + 1, cur = left;
    for (int i = left; i <= right; ++i) backup[i - left] = nums[i];
    while (cur_l <= mid - left && cur_r <= right - left) {
        if (backup[cur_l] <= backup[cur_r]) {
            nums[cur++] = backup[cur_l++];
        } else {
            nums[cur++] = backup[cur_r++];
        }
    }
    while (cur_l <= mid - left) nums[cur++] = backup[cur_l++];
    while (cur_r <= right - left) nums[cur++] = backup[cur_r++];
}

void merge_sort(int nums[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void print_array(int nums[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int nums[5] = {2, 1, 5, 4, 3};
    merge_sort(nums, 0, 4);
    print_array(nums, 5);
    return 0;
}
