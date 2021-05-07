function encryptCustomKey(beforeKey) {
    var b_key = [];
    var r_key = new Array(16);

    for (var i = 0; i < beforeKey.length; ++i) {
        b_key.push(beforeKey.charCodeAt(i));
    }

    for (var i = 0; i < 8; ++i) {
        var temp = (b_key[i] ^ 0xfef0) % 100 + 27;
        if (temp - 32 <= 0) {
            temp += 32;
        }
        r_key[i] = (b_key[15 - i] ^ 0xfabc) % 100 + 27;
        if (r_key[i] - 32 <= 0) {
            r_key[i] += 32;
        }
        r_key[15 - i] = temp;
    }
    return String.fromCharCode(...r_key);
}

var res = encryptCustomKey("1234一二三四abcd😋😋😋😋");
console.log(res);