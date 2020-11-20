let twoSum = function(nums, target) {
    let m = {};
    for (let i = 0; i < nums.length; ++i) {
        let item = nums[i];
        let rem = target - item;
        if (rem in m) {
            return [m[rem], i];
        }
        m[item] = i;
    }
    return [];
};

let arr = [2, 5, 7, 9];
let target = 7;

console.log(twoSum(arr, target));
