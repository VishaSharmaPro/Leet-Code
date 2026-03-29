// google amazon microsoft meta bloomberg axon linkedin swiggy tiktok cisco flipkart deloitte oracle zoho walmart epam accenture visa
class Solution {
public:
    int t[501][501];
    int solve(int i,int j,string &word1, string &word2){
        if(j>= word2.length()) return word1.length() - i;
        if(i>= word1.length()) return word2.length() - j;
        if(t[i][j] != -1) return t[i][j];
        int find = 501;
        if(word1[i] == word2[j]){
            find = solve(i+1,j+1,word1,word2);
        }
        int replace = 1 + solve(i+1,j+1,word1,word2);
        int delet = 1 + solve(i+1,j,word1,word2);
        int insert = 1 + solve(i,j+1,word1,word2);
        return t[i][j] = min({find,replace,delet,insert});
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,word1,word2);
    }
};
