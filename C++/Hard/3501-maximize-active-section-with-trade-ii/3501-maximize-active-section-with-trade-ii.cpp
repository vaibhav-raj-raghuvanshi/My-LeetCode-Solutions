class Solution {
public:
    vector<int> zeroStart, zeroEnd;
    vector<int> valley;
    vector<vector<int>> sparse;

    int rmq(int left, int right){
        int len = right - left + 1;
        int k = 0;
        while((1 << (k + 1)) <= len){
            k++;
        }
        return max(sparse[k][left], sparse[k][right - (1 << k) + 1]);
    }

    int clip(int idx, int left, int right){
        int sol = valley[idx];
        if(left > zeroStart[idx]){
            sol -= left - zeroStart[idx];
        }
        if(right < zeroEnd[idx + 1]){
            sol -= zeroEnd[idx + 1] - right;
        }
        return sol;
    }

    int gain(int left, int right){
        if(zeroStart.size() < 2){
            return 0;
        }
        int leftValley = lower_bound(zeroEnd.begin(), zeroEnd.end(), left) - zeroEnd.begin();
        int rightValley = upper_bound(zeroStart.begin(), zeroStart.end(), right) - zeroStart.begin() - 2;
        if(leftValley > rightValley){
            return 0;
        }
        int sol = max(clip(leftValley, left, right), clip(rightValley, left, right));
        if(rightValley - leftValley >= 2){
            sol = max(sol, rmq(leftValley + 1, rightValley - 1));
        }
        return sol;
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = 0;
        for(char ch : s){
            if(ch == '1'){
                ones++;
            }
        }
        for(int i = 0; i < n; ){
            if(s[i] == '0'){
                int j = i;
                while(j < n && s[j] == '0'){
                    j++;
                }
                zeroStart.push_back(i);
                zeroEnd.push_back(j - 1);
                i = j;
            }else{
                i++;
            }
        }
        int blocks = zeroStart.size();
        for(int i = 0; i + 1 < blocks; i++){
            int len1 = zeroEnd[i] - zeroStart[i] + 1;
            int len2 = zeroEnd[i + 1] - zeroStart[i + 1] + 1;
            valley.push_back(len1 + len2);
        }
        sparse.push_back(valley);
        for(int len = 1; len * 2 <= valley.size(); len *= 2){
            vector<int> curr;
            for(int i = 0; i + len < sparse.back().size(); i++){
                curr.push_back(max(sparse.back()[i], sparse.back()[i + len]));
            }
            sparse.push_back(curr);
        }
        vector<int> sol;
        for(auto it : queries){
            sol.push_back(ones + gain(it[0], it[1]));
        }
        return sol;
    }
};