function add(a, b) {
    var la = a.length - 1, lb = b.length - 1;
    var res = '';
    var sum = 0;
    while (la >= 0 || lb >= 0 || sum > 0) {
        if (la >= 0) sum += parseInt(a[la--]);
        if (lb >= 0) sum += parseInt(b[lb--]);
        res = (sum%10) + res;
        sum = Math.floor(sum / 10);
    }
    return res;
}

console.log(add('123', '456'))
console.log(add('1', '999'))
console.log(add('999', '9'))
console.log(add('10', '990'))
console.log(add('123', '999'))
