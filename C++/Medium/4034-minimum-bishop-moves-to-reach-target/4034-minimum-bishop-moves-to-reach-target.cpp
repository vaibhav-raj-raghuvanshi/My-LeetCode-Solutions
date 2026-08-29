class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(((source[0] + source[1]) % 2) != ((target[0] + target[1]) % 2)){
            return -1;
        }
        if(abs(target[1] - source[1]) == abs(target[0] - source[0])){
            return 1;
        }
        return 2;
    }
};