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

    void build(int two, int three) {

        minCount2D.assign(two + 1, vector<int>(three + 1, INT_MAX / 2));
        minCount2D[0][0] = 0;

        vector<pair<int, int>> digits = {
            {1, 0},
            {0, 1},
            {2, 0},
            {1, 1},
            {3, 0},
            {0, 2}
        };

        for(int i = 0; i <= two; i++) {

            for(int j = 0; j <= three; j++) {

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

    vector<int> reduce(vector<int> need, int digit) {

        for(int i = 0; i < 4; i++) {
            need[i] = max(0, need[i] - digitContri[digit][i]);
        }

        return need;
    }

    int minCount(vector<int> need) {

        return minCount2D[need[0]][need[1]] + need[2] + need[3];
    }

    bool canFill(vector<int> need, int length) {

        return minCount(need) <= length;
    }

    string buildSuffix(vector<int> need, int length) {

        string sol = "";

        for(int i = 0; i < length; i++) {

            int remaining = length - i - 1;

            for(int digit = 1; digit <= 9; digit++) {

                vector<int> newNeed = reduce(need, digit);

                if(canFill(newNeed, remaining)) {

                    sol.push_back(digit + '0');
                    need = newNeed;
                    break;
                }
            }
        }

        return sol;
    }

public:
    string smallestNumber(string num, long long t) {

        int needTwo = 0;
        int needThree = 0;
        int needFive = 0;
        int needSeven = 0;

        long long temp = t;

        while(temp % 2 == 0) {
            temp /= 2;
            needTwo++;
        }

        while(temp % 3 == 0) {
            temp /= 3;
            needThree++;
        }

        while(temp % 5 == 0) {
            temp /= 5;
            needFive++;
        }

        while(temp % 7 == 0) {
            temp /= 7;
            needSeven++;
        }

        if(temp != 1) {
            return "-1";
        }

        build(needTwo, needThree);

        vector<int> fullNeed = {
            needTwo,
            needThree,
            needFive,
            needSeven
        };

        int n = num.size();

        {
            vector<int> need = fullNeed;

            bool hasZero = false;

            for(char ch : num) {

                if(ch == '0') {
                    hasZero = true;
                    break;
                }

                need = reduce(need, ch - '0');
            }

            if(!hasZero && need == vector<int>{0, 0, 0, 0}) {
                return num;
            }
        }

        int firstZero = n;

        for(int i = 0; i < n; i++) {

            if(num[i] == '0') {
                firstZero = i;
                break;
            }
        }

        vector<vector<int>> prefixNeed(n + 1);

        prefixNeed[0] = fullNeed;

        for(int i = 0; i < n; i++) {

            if(num[i] == '0') {
                prefixNeed[i + 1] = prefixNeed[i];
            }
            else {
                prefixNeed[i + 1] = reduce(prefixNeed[i], num[i] - '0');
            }
        }

        int last = min(n - 1, firstZero);

        for(int i = last; i >= 0; i--) {

            vector<int> need = prefixNeed[i];

            int startDigit;

            if(num[i] == '0') {
                startDigit = 1;
            }
            else {
                startDigit = num[i] - '0' + 1;
            }

            for(int digit = startDigit; digit <= 9; digit++) {

                vector<int> newNeed = reduce(need, digit);

                int remaining = n - i - 1;

                if(canFill(newNeed, remaining)) {

                    string sol = num.substr(0, i);

                    sol.push_back(digit + '0');
                    sol.append(buildSuffix(newNeed, remaining));

                    return sol;
                }
            }
        }

        int minimumLength = minCount(fullNeed);
        int finalLength = max(n + 1, minimumLength);

        return buildSuffix(fullNeed, finalLength);
    }
};