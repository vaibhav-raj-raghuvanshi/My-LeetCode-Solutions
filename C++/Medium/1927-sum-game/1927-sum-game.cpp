class Solution {
public:
    bool sumGame(string s) {
        int res = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int sign;
            if (i < n / 2) {
                sign = 2;
            } else {
                sign = -2;
            }
            int value;
            if (s[i] == '?') {
                value = 9;
                res -= 9 * sign/2;
            } else {
                value = s[i] - '0';
            }
            res += sign * value;
        }
        if (res != 0.0) {
            return true;
        } else {
            return false;
        }
    }
};