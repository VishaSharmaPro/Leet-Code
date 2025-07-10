//Company Tags                : GOOGLE
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();
        int cs = 0;
        int ct  = 0;
        for(int i = m; i>=0 ; i--){
            char ch = s[i];
            if(ch == '#'){
                cs += 1;
                s.erase(i,1);
            }
            if(cs != 0 && ch != '#'){
                s.erase(i,1);
                cs--;
            }
        }
        for(int i = n; i>=0 ; i--){
            char cht = t[i];
            if(cht == '#'){
                ct += 1;
                t.erase(i,1);
            }
            if(ct != 0 && cht != '#'){
                t.erase(i,1);
                ct--;
            }
        }
        return s == t;
    }
};
