#define ll long long
class Solution {
private:
    string s;
    int n;
    vector<vector<vector<ll>>> dpCount;
    vector<vector<vector<ll>>> dpWave;
    pair<ll, ll> solve(int idx, int prevPrev, int prev, bool isTight, bool isLeading){
        if(idx == n){
            return {1, 0};
        }
        if(!isTight && !isLeading && prevPrev != -1 && prev != -1){
            if(dpCount[idx][prevPrev][prev] != -1){
                return {dpCount[idx][prevPrev][prev],dpWave[idx][prevPrev][prev]};
            }
        }
        ll totalCount = 0;
        ll totalWave = 0;
        int limit = isTight ? s[idx] - '0' : 9;
        for(int digit = 0; digit <= limit; digit++){
            bool newLeading = isLeading && (digit == 0);
            int newPrevPrev = prev;
            int newPrev = newLeading ? -1 : digit;
            auto [count, wave] = solve(idx + 1,newPrevPrev,newPrev,isTight && (digit == limit),newLeading);
            if(!newLeading && prevPrev != -1 && prev != -1){
                if((prevPrev < prev && prev > digit) || (prevPrev > prev && prev < digit)){
                    totalWave += count;
                }
            }
            totalCount += count;
            totalWave += wave;
        }
        if(!isTight && !isLeading && prevPrev != -1 && prev != -1){
            dpCount[idx][prevPrev][prev] = totalCount;
            dpWave[idx][prevPrev][prev] = totalWave;
        }
        return {totalCount, totalWave};
    }
    ll func(ll num){
        if(num < 100){
            return 0;
        }
        s = to_string(num);
        n = s.size();
        dpCount.assign(n, vector<vector<ll>>(10, vector<ll>(10, -1)));
        dpWave.assign(n, vector<vector<ll>>(10, vector<ll>(10, -1)));
        return solve(0, -1, -1, 1, 1).second;
    }
public:
    ll totalWaviness(ll num1, ll num2) {
        return func(num2) - func(num1 - 1);
    }
};