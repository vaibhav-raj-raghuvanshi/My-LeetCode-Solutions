class Solution {
private:
    vector<vector<int>> minCount2D;
    vector<vector<int>> digitContri = {
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {1, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {2, 0, 0, 0}, 
        {0, 0, 1, 0}, 
        {1, 1, 0, 0}, 
        {0, 0, 0, 1}, 
        {3, 0, 0, 0}, 
        {0, 2, 0, 0}  
    };
    void build(int Two, int Three) {
        minCount2D.assign(Two + 1, vector<int>(Three + 1, INT_MAX / 2));
        minCount2D[0][0] = 0;
        vector<pair<int, int>> digits = {
            {1, 0},
            {0, 1},
            {2, 0},
            {1, 1},
            {3, 0},
            {0, 2}
        };
        for(int i = 0; i <= Two; i++) {
            for(int j = 0; j <= Three; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                int best = INT_MAX / 2;
                for(auto &it : digits) {
                    int prevTwo = max(0, i - it.first);
                    int prevThree = max(0, j - it.second);
                    best = min(best, minCount2D[prevTwo][prevThree] + 1);
                }
                minCount2D[i][j] = best;
            }
        }
    }
    array<int,4> reduce(array<int,4> Need, int Digit) {
        for(int i = 0; i < 4; i++) {
            Need[i] = max(0, Need[i] - digitContri[Digit][i]);
        }
        return Need;
    }
    int minCount(array<int,4> Need) {
        return minCount2D[Need[0]][Need[1]] + Need[2] + Need[3];
    }
    bool canFill(array<int,4> Need, int Length) {
        return minCount(Need) <= Length;
    }
    string buildSuffix(array<int,4> Need, int Length) {
        string Ans = "";
        for(int i = 0; i < Length; i++) {
            int Remaining = Length - i - 1;
            for(int Digit = 1; Digit <= 9; Digit++) {
                auto NewNeed = reduce(Need, Digit);
                if(canFill(NewNeed, Remaining)) {
                    Ans.push_back(Digit + '0');
                    Need = NewNeed;
                    break;
                }
            }
        }
        return Ans;
    }
public:
    string smallestNumber(string num, long long t) {
        int NeedTwo = 0;
        int NeedThree = 0;
        int NeedFive = 0;
        int NeedSeven = 0;
        long long Temp = t;
        while(Temp % 2 == 0) {
            Temp /= 2;
            NeedTwo++;
        }
        while(Temp % 3 == 0) {
            Temp /= 3;
            NeedThree++;
        }
        while(Temp % 5 == 0) {
            Temp /= 5;
            NeedFive++;
        }
        while(Temp % 7 == 0) {
            Temp /= 7;
            NeedSeven++;
        }
        if(Temp != 1) {
            return "-1";
        }
        build(NeedTwo, NeedThree);
        array<int,4> FullNeed = {
            NeedTwo,
            NeedThree,
            NeedFive,
            NeedSeven
        };
        int n = num.size();
        {
            array<int,4> Need = FullNeed;
            bool HasZero = false;
            for(char ch : num) {
                if(ch == '0') {
                    HasZero = true;
                    break;
                }
                Need = reduce(Need, ch - '0');
            }
            if(!HasZero && Need == array<int,4>{0,0,0,0}) {
                return num;
            }
        }
        int FirstZero = n;
        for(int i = 0; i < n; i++) {
            if(num[i] == '0') {
                FirstZero = i;
                break;
            }
        }
        vector<array<int,4>> PrefixNeed(n + 1);
        PrefixNeed[0] = FullNeed;
        for(int i = 0; i < n; i++) {
            if(num[i] == '0') {
                PrefixNeed[i + 1] = PrefixNeed[i];
            }
            else {
                PrefixNeed[i + 1] = reduce(PrefixNeed[i], num[i] - '0');
            }
        }
        int Last = min(n - 1, FirstZero);
        for(int i = Last; i >= 0; i--) {
            auto Need = PrefixNeed[i];
            int StartDigit;
            if(num[i] == '0') {
                StartDigit = 1;
            }
            else {
                StartDigit = num[i] - '0' + 1;
            }
            for(int Digit = StartDigit; Digit <= 9; Digit++) {
                auto NewNeed = reduce(Need, Digit);
                int Remaining = n - i - 1;
                if(canFill(NewNeed, Remaining)) {
                    string Ans = num.substr(0, i);
                    Ans.push_back(Digit + '0');
                    Ans += buildSuffix(NewNeed, Remaining);
                    return Ans;
                }
            }
        }
        int MinimumLength = minCount(FullNeed);
        int FinalLength = max(n + 1, MinimumLength);
        return buildSuffix(FullNeed, FinalLength);
    }
};