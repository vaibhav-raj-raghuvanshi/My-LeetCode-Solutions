class Solution {
public:
    string numberToWords(int num){
        if(num == 0){
            return "Zero";
        }
        string bigString[] = {"Thousand", "Million", "Billion"};
        string sol = numberToWordsHelper(num % 1000);
        num /= 1000;
        for(int i = 0; i < 3; i++){
            if(num > 0 && num % 1000 > 0){
                sol = numberToWordsHelper(num % 1000) + bigString[i] + " " + sol;
            }
            num /= 1000;
        }
        if(!sol.empty()){
            sol = sol.substr(0, sol.size() - 1);
        }
        return sol;
    }

    string numberToWordsHelper(int num){
        string digitString[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teenString[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tenString[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string sol = "";
        if(num > 99){
            sol += digitString[num / 100] + " Hundred ";
        }
        num %= 100;
        if(num < 20 && num > 9){
            sol += teenString[num - 10] + " ";
        }else {
            if(num >= 20){
                sol += tenString[num / 10] + " ";
            }
            num %= 10;
            if(num > 0){
                sol += digitString[num] + " ";
            }
        } 
        return sol;
    }
};