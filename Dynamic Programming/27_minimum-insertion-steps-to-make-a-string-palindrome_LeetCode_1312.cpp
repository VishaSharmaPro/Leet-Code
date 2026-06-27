// google amazon orcale accenture
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int j,string &s){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int li = 0;
        int ri = 0;
        if(s[i] == s[j]){
            li = solve(i+1,j-1,s);
            ri = solve(i+1,j-1,s);
        }
        if(s[i] != s[j]){
            ri = 1 + solve(i+1,j,s);
            li = 1 + solve(i,j-1,s);
        }
        return dp[i][j] =  min(li,ri);
    }
    int minInsertions(string s) {
        n = s.length();
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        return solve(0,n-1,s);
    }
};
