#define vi vector<int>
#define vb vector<bool>
class Solution {
public:
    vector<int> grayCode(int n) {
        int curr = 0;
        vi sol = {0};
        int sz = (1 << n) - 1;
        vb visited(sz+2,false);
        visited[0] = true;
        while(sz){
            for(int i = 0;i < 17;i++){
                if(!visited[curr ^ (1 << i)]){
                    int temp = curr ^ (1 << i);
                    sol.push_back(temp);
                    curr = temp;
                    visited[temp] = true;
                    sz--;
                    break;
                }
            }
        }
        return sol;
    }
};