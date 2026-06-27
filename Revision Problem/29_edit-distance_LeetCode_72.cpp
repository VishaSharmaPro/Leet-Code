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

// method 2
/*
continue isliye likha taaki else block execute na ho aur dp[i][j] overwrite na ho.
Bina continue ke yeh hota:
cppif(word1[i] == word2[j]){
    dp[i][j] = dp[i+1][j+1];  // ✅ Sahi value set hui
}
else{
    insert = ...; replace = ...; del = ...;
}
dp[i][j] = min({0, 0, 0});  // ❌ 0 se overwrite ho gaya!
insert, replace, del sab 0 hain, toh min({0,0,0}) = 0 se overwrite ho jaata tha.
continue se loop ka next iteration chala jaata hai — dp[i][j] = min(...) line skip ho jaati hai. ✅
*/
class Solution {
public:
    int m;
    int n;
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        vector<vector<int>> dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int j = 0;j<=n;j++) dp[m][j] = n-j;
        for(int i = 0;i<=m;i++) dp[i][n] = m-i;
        for(int i = m-1;i>=0;i--){
            for(int j =n-1;j>=0;j--){
                int insert = 0, replace = 0, del = 0;
                if(word1[i] == word2[j]){
                    dp[i][j] =  dp[i+1][j+1];
                    continue;
                } 
                else{
                    insert = 1 + dp[i][j+1];
                    replace = 1 + dp[i+1][j+1];
                    del = 1 + dp[i+1][j];
                }
                dp[i][j] = min({insert,replace,del});
            }
        }
        return dp[0][0];
    }
};

// method 3   without continue
class Solution {
public:
    int m;
    int n;
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        vector<vector<int>> dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int j = 0;j<=n;j++) dp[m][j] = n-j;
        for(int i = 0;i<=m;i++) dp[i][n] = m-i;
        for(int i = m-1;i>=0;i--){
            for(int j =n-1;j>=0;j--){
                if(word1[i] == word2[j]){
                    dp[i][j] =  dp[i+1][j+1];
                } 
                else {
                    int insert = 1 + dp[i][j+1];
                    int replace = 1 + dp[i+1][j+1];
                    int del = 1 + dp[i+1][j];
                    dp[i][j] = min({insert, replace, del});  // ✅ Sirf else mein
                }
            }
        }
        return dp[0][0];
    }
};
