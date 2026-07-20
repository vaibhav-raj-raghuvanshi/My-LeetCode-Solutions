#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> sol;
        int currX = nums[0][0],currY = nums[0][1];
        for(auto it: nums){
            if(it[0] <= currY){
                currY = max(currY,it[1]);
            }else{
                sol.push_back({currX,currY});
                currX = it[0];
                currY = it[1];
            }
        }
        sol.push_back({currX,currY});
        return sol;
    }
};