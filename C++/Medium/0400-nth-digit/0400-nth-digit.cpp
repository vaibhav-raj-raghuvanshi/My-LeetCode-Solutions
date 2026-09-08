class Solution {
public:
    int findNthDigit(int n) {
        long long r = 9;
        long long ctr = 1;
        long long start = 1;
        while (n > r * ctr) {
            n -= r * ctr;
            ctr++;
            r *= 10;
            start *= 10;
        }
        long long num = start + (n - 1) / ctr;
        int digitIndex = (n - 1) % ctr;
        string s = to_string(num);
        return s[digitIndex] - '0';
    }
};