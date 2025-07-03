class Solution {
public:
    char kthCharacter(int k) {
        int len = 1;
        while (len < k) len *= 2;

        int shift = 0;
        while (len > 1) {
            if (k <= len / 2) {
                len /= 2;
            } else {
                k -= len / 2;
                shift++;
                len /= 2;
            }
        }
        char c = 'a' + shift;
        if (c > 'z') c -= 26;
        return c;
    }
};
