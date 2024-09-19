/**
 * @param {number} N
 * @return {number}
 */
var monotoneIncreasingDigits = function(N) {
    if (N < 10) return N;
    let last = 1 << 30, mx = 1, lx = 1, n = N;
    while (N > 0) {
        let cur = N % 10;
        if (cur > last) {
            cur = cur - 1;
            lx = mx;
        }

        mx = mx * 10;
        last = cur;
        N = parseInt(N / 10);
    }

    return (parseInt(n / lx)) * lx - (lx > 1 ? 1 : 0);
};

let res = monotoneIncreasingDigits(10);
console.log(res);
