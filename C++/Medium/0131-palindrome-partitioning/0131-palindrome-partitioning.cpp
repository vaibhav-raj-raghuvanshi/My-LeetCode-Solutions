class Solution {
private:
    int n;
    vector<vector<string>> sol;
    bool isPalindrome(string &str){
        int low = 0;
        int high = str.size() - 1;
        while(low < high){
            if(str[low] != str[high]){
                return false;
            }
            high--;
            low++;
        }
        return true;
    }
    void backtrack(int start, vector<string> &temp,string &str){
        if(start == n){
            sol.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){
            string tempStr = str.substr(start, i-start+1);
            if(isPalindrome(tempStr)){
                temp.push_back(tempStr);
                backtrack(i+1, temp, str);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> temp;
        backtrack(0, temp, s);
        return sol;
    }
};