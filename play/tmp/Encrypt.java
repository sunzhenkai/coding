public class Encrypt {
    public static String encryptCustomKey(String beforeKey) {
        char[] b_key = beforeKey.toCharArray();
        char[] r_key = new char[16];
        for (int i = 0; i < 8; ++i) {
            char temp = (char) ((b_key[i] ^ 0xfef0) % 100 + 27);
            if (temp - 32 <= 0) {
                temp += 32;
            }
            r_key[i] = (char) ((b_key[15 - i] ^ 0xfabc) % 100 + 27);
            if (r_key[i] - 32 <= 0) {
                r_key[i] += 32;
            }
            r_key[15 - i] = temp;
        }

        return String.valueOf(r_key);
    }

    public static void main(String[] args) {
        String s = "1234一二三四abcd😋😋😋😋";
        System.out.println(encryptCustomKey(s));
    }
}
