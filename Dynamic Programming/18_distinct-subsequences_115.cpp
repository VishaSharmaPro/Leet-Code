// google meta microsoft amazon zoho bloomberg jpmorgan swiggy oracle walmart coupang trilogy meesho 
class Solution {
public:
    int td[1001][1001];
    int solve(int i,int j,string &s,string &t){
        if(j>= t.length()) return 1;
        if(i>=s.length()) return 0;
        if(td[i][j] != -1) return td[i][j];
        int take = 0;
        if(s[i] == t[j]){
            take = solve(i+1,j+1,s,t);
        }
        int skip = solve(i+1,j,s,t);
        return td[i][j] = skip + take;
    }
    int numDistinct(string s, string t) {
        memset(td,-1,sizeof(td));
        return solve(0,0,s,t);
    }
};
