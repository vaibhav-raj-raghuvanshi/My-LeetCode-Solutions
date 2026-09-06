class Solution {
private:
    void convert(char ch, long long int &x){
        int bit = ch - '0';
        x <<= 1;
        x |= bit;
    }
    void convert(long long int &x, long long int low, long long int high){
        long long int t = (1ll << (high-low+1)) - 1;
        x &= t;
    }
public:
    bool queryString(string s, int n) {
        long long int low = 0, sol = 0;
        long long int x = 0;
        unordered_map<int, int>mp;
        for(int high = 0; high < s.size();high++){
            convert(s[high], x);
            while(low <= high && x > n){
                low++;
                convert(x, low, high);
            }
            if(x!=0 && ++mp[x] == 1){
                sol++;
            }
        }
        // n = n-1
        while(low < s.size() && x > n){
            low++;
            convert(x, low, s.size()-1);
        }
        while(low < s.size()){
            convert(x, low, s.size()-1);
            if(x!=0 && ++mp[x] == 1){
                sol++;
            }
            low++;
        }
        return sol == n;
    }
};