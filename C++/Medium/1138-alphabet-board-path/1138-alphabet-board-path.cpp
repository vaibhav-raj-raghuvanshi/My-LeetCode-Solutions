class Solution {
private:
    void help(int ci, int cj, int fi, int fj, string &sol){
        while(ci < fi){
            sol.push_back('D');
            ci++;
        }
        while(ci > fi){
            sol.push_back('U');
            ci--;
        }
        while(cj < fj){
            sol.push_back('R');
            cj++;
        }
        while(cj > fj){
            sol.push_back('L');
            cj--;
        }
    }
public:
    string alphabetBoardPath(string target) {
        int currI = 0, currJ = 0;
        string sol = "";
        for(auto it : target){
            int toI = (it - 'a')/5,toJ = (it - 'a') % 5;
            if(currI == 5 && toI == 5){
            }else if(currI == 5){
                sol.push_back('U');
                help(4, 0, toI, toJ, sol);
            }else if(toI == 5){
                help(currI, currJ, 4, 0, sol);
                sol.push_back('D');
            }else{
                help(currI, currJ, toI, toJ, sol);
            }
            sol.push_back('!');
            currI = toI;
            currJ = toJ;
        }
        return sol;
    }
};