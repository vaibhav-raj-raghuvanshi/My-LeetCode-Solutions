class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> sol = {1,9,81,648,4536,27216,136080,544320,1632960};
        return accumulate(sol.begin(), sol.begin() + n + 1, 0ll);
    }
};