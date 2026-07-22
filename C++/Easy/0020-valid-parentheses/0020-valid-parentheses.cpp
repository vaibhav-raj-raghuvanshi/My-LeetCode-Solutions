class Solution {
private:
    stack<char> st;
    bool isOpen(char ch){
        if(ch == '(' ||ch == '{' ||ch == '['){
            return true;
        }
        return false;
    }
    bool isMatching(char ch){
        if(st.empty()){
            return false;
        }
        if((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[')){
            return true;
        }
        return false;
    }
public:
    bool isValid(string s) {
        for(auto it : s){
            if(isOpen(it)){
                st.push(it);
            }
            else{ 
                if(isMatching(it)){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};