function qsort(nums, left, right) {
    if (left >= right) return;

    var pivot = nums[left], i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] > pivot) --j;
        nums[i] = nums[j];

        while (i < j && nums[i] <= pivot) ++i;
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    qsort(nums, left, i-1);
    qsort(nums, i+1, right);
}

var v;
v = [3, 2, 1, 3, 4, 0, -1, 8, 9, 1, 0];
qsort(v, 0, v.length - 1);
console.log(v);
