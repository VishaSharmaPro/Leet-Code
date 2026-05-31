// google amazon microsoft meta bloomberg tiktok motive pornhub alibaba roku tekion linkedin goldman jpmorgan
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> st;
        stack<int> cs;
        for(int i = 0;i<n;i++){
            if(s[i] == '*') cs.push(i);
            else if(s[i] == '(' ){
                st.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                }
                else if(!cs.empty()){
                    cs.pop();
                }else{
                    return false;
                }
            }
        }
        while(!st.empty() && !cs.empty()){
            if(st.top() > cs.top()) return false;  //  is vale test case ke liye == '(*'
            st.pop();
            cs.pop();
        }
        return st.empty();
    }
};
