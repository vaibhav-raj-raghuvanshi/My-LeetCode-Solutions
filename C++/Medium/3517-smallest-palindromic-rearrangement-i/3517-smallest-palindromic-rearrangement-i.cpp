class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> mp(26, 0);
        for(auto it : s){
            mp[it - 'a']++;
        }
        int low = 0,high = n-1;
        int i = 0;
        while(i < 26 && high > low){
            while(mp[i] >= 2){
                s[low++] = i + 'a';
                s[high--] = i + 'a';
                mp[i]-=2;
            }
            i++;
        }
        return s;
    }
};