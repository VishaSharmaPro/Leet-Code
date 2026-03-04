// ggole amazon meta mircosoft udemy cerner nvidia  linkedin oracle apple ituit tesla tripadvisior adobe visa walamart spotify turing yandex
class Solution {
public:
    char invert(char & ch){
        if(ch == '}'){
            return '{';
        }
        else if(ch == ']'){
            return '[';
        }
        else{
            return '(';
        }
    }
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(char & ch : s){
            if(ch == '{' || ch == '[' || ch =='('){
                st.push(ch);
            }
            else{
                char x = 'default';
                if(!st.empty()) x = st.top();
                st.pop();
                char inv = invert(ch);
                if(x != inv) return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
