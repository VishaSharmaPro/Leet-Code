// google amazon bloomberg zoho microsoft zopsmart tiktok agoda apple meta oracle razorpay cisco goldman wix tinkoff coupang activion cyntexa
class Solution {
public:
    void doubfunc(string &st, int freq) {
        string original = st;
        for(int i = 1; i < freq; i++) {
            st += original;
        }
    }
    string decodeString(string s) {
        stack<char> st;
        int n = s.length();
        string temp = "";
        for(int  i = 0;i<n;i++){
            if(s[i] == ']'){
                while(st.top() != '['){
                   temp = st.top() + temp;
                   st.pop(); 
                }
                st.pop();   // [ hatane ke liye
                 string numStr = "";
                while(!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                int freq = stoi(numStr);
                doubfunc(temp,freq);
                int nt = temp.length();
                for(int j = 0; j < nt; j++){   // fix: forward order
                    st.push(temp[j]);
                }
                temp = "";
                continue;
            }
            st.push(s[i]);
        }
        string ans = "";
        int sz = st.size();
        for(int i = 0;i<sz;i++){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
