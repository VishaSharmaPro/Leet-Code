// google amazon microsoft meta bloomberg zoho coupang walmart oracle deshaw x(twitter) atlassian
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;
    bool solve(int i,int j,string &s, string &p){
        if(j>=n){
            while(i<m) if(s[i++] != '*') return false;
            return true;
        }
        if(i>= m){
            while(j<n) if(p[j++] != '*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool take = false, onetake = false,multipletake = false,notake = false;
        if(p[j] == '?'){
            take = solve(i+1,j+1,s,p);
        }else if(p[j] == '*'){
            onetake = solve(i+1,j+1,s,p);
            multipletake = solve(i+1,j,s,p);
            notake = solve(i,j+1,s,p);
        }else{
            if(s[i] == p[j]) take = solve(i+1,j+1,s,p);
        }
        return dp[i][j] = take || onetake || multipletake || notake;
    }
    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        return solve(0,0,s,p);
    }
};
