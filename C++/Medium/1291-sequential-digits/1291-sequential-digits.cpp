class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sol;
        for(int len = 2; len <= 9; len++){
            for(int start = 1; start + len - 1 <= 9; start++){
                int num = 0;
                int digit = start;
                for(int i = 0; i < len; i++){
                    num = num * 10 + digit;
                    digit++;
                }
                if(num >= low && num <= high){
                    sol.push_back(num);
                }
            }
        }
        return sol;
    }
};