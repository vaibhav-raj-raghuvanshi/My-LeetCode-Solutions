class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        if(stol(str) > INT_MAX || stol(str) <= n){
            return -1;
        }
        return stoi(str);
    }
};