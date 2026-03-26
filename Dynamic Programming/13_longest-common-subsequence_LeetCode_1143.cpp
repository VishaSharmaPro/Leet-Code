// google amazon microsoft meta bloomberg doordash bytedance optum walmart tiktok oracle accolite morganstanley
class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,string& text1,string& text2){
        if(i>= text1.length() || j>= text2.length()){
            return 0;
        }
        if(t[i][j] != -1) return t[i][j];
        int take = 0;
        if(text1[i] == text2[j]){
            take = 1 + solve(i+1,j+1,text1,text2);
        }
        int firstleave = solve(i+1,j,text1,text2);
        int secondleave = solve(i,j+1,text1,text2);
        return t[i][j] = max({take,firstleave,secondleave});
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,text1,text2);
    }
};
