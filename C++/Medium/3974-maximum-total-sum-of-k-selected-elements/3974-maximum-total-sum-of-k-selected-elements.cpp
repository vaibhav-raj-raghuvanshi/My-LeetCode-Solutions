#include <bits/stdc++.h>
using namespace std;

#define ll __int128
#define ull unsigned long long

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>

#define pb push_back
#define eb emplace_back

#define ff first
#define ss second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define um unordered_map
#define us unordered_set

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

template<typename T>
inline bool chmax(T &a,const T &b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
inline bool chmin(T &a,const T &b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(rall(nums));
        ll sol = 0;
        for(int i = 0;i < k;i++){
            if(mul > 0){
                sol += 1ll * nums[i] * mul;
                mul--;
            }else{
                sol += nums[i];
            }
        }
        return sol;
    }
};