// google amazon microsoft meta bloomberg zoho jpmorgan oracle meesho  coupang trilogy
// method 1
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

//method 2
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        for(int i = 0;i<=m;i++) dp[i][n] = 1;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                unsigned long long take = 0, skip = 0;
                if(s[i] == t[j]){
                    take = dp[i+1][j+1];
                }
                skip = dp[i+1][j];
                dp[i][j] = take + skip;
            }
        }
        return (int)dp[0][0];
    }
};
