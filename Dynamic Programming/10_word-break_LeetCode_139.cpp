// google amazon meta bloomberg microsoft uber zeta apple ituit linkedin mongodb walmart tiktok netflix orcale
class Solution {
public:
    int t[301][301];
    unordered_map<string,int> mp;
    bool solve(int i,int j,string s){
        if(i>=s.length()) return true;
        if(j >= s.length()) return false;
        if(t[i][j] != -1) return t[i][j];
        string word = s.substr(i, j-i+1); 
        if(mp[word] == 1 && solve(j+1, j+1, s)){
            return t[i][j] = 1;
        }
        return t[i][j] = solve(i,j+1,s);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
        for(int i = 0;i<wordDict.size();i++){
            mp[wordDict[i]] = 1;
        }
        return solve(0,0,s);
    }
};

// on 2/7/26
class Solution {
public:
    int n;
    unordered_map<string,int> dict;
    
    
    vector<vector<int>> dp;
    bool solve(int i,int j,string &s){
        if(i == n) return true;
        if(j>=n) return false;
        if(dp[i][j] != -1) return dp[i][j];
        
        string temp = s.substr(i,j-i+1);
        bool take = false;
        if(dict.find(temp) != dict.end()){
            take = solve(j+1,j+1,s);
        }
        bool skip = false;
        skip = solve(i,j+1,s);
        return dp[i][j] = take || skip;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for(auto it : wordDict){
            dict[it]++;
        }
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        return solve(0,0,s);
        
    }
};
