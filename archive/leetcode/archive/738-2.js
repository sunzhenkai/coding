/**
 * @param {number} N
 * @return {number}
 */
var monotoneIncreasingDigits = function(N) {
    if (N < 10) return N;
    let last = 1 << 30, mx = 1, res = 0, cur = 0;
    while (N > 0) {
        cur = N % 10;
        if (cur > last) {
            cur = cur - 1;
            res = mx - 1;
        }

        N = parseInt(N / 10);
        res = res + cur * mx;
        mx = mx * 10;
        last = cur;
    }
    return res;
};

let res = monotoneIncreasingDigits(10);
console.log(res);
