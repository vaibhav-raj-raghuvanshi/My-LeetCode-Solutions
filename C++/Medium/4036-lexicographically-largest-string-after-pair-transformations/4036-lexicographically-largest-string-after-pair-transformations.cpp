class Solution {
private:
    int mx;
    string render(int num){
        int ctrZ = 0;
        while(num >= mx){
            num -= mx;
            ctrZ++;
        }
        int i = 0;
        string sol = "";
        while(num > 0){
            if(num % 2 == 1){
                sol.push_back(i + 'a');
            }
            i++;
            num /= 2;
        }
        while(ctrZ > 0){
            ctrZ--;
            sol.push_back('z');
        }
        reverse(sol.begin(), sol.end());
        
        return sol;
    }
public:
    vector<string> largestString(vector<int>& nums) {
        vector<pair<char, int>> values;
        mx = 1 << 25;
        // for(int i = 0; i < 26; i++){
        //     values.push_back({'a' + i, 1 << i});
        // }
        vector<string> sol;
        for(auto it : nums){
            sol.push_back(render(it));
        }
        return sol;
    }
};