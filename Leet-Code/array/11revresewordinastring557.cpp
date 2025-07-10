class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int st = 0;
        for(int i = 0;i<=n;i++){
            if(i == n ||  s[i] == ' '){
                if(i-1 >=0){
                    reverse(s.begin() + st, s.begin() + i);
                    st = i+1;
                }
                
            }
                
        }
        return s;
    }
};
