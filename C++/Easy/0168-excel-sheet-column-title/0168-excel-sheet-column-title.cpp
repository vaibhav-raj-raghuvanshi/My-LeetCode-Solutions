class Solution {
public:
    string convertToTitle(int n) {
        string sol = "";
        while(n > 0){
            int curr = n % 26 - 1;
            curr = (curr + 26) % 26;
            sol.push_back('A' + curr);
            n -= (curr + 1);
            n /= 26;
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};