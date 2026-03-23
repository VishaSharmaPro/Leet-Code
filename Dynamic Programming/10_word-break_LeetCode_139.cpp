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
