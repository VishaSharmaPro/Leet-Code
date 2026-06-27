// google amazon microsoft meta apple bloomberg axon tiktok linkedin  zoho flipkart deloitte oracle walmart epam_systems
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;
    int solve(int i,int j,string &s,string &t){
        if(i>=m) return n-j;
        if(j>=n) return m-i;
        if(dp[i][j] != -1) return dp[i][j];
        int insert = 0, replace = 0, del = 0;
        if(s[i] == t[j]) return dp[i][j] =  solve(i+1,j+1,s,t);
        else{
            insert = 1 + solve(i,j+1,s,t);
            replace = 1 + solve(i+1,j+1,s,t);
            del = 1 + solve(i+1,j,s,t);
        }
        return dp[i][j] = min({insert,replace,del});
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        dp = vector<vector<int>>(m+1,vector<int>(n+1,-1));
        return solve(0,0,word1,word2);
    }
};
