// google microsoft amazon meta bloomberg apple zeta nuro zoho ebay thoughtspot
class Solution {
public:
    int t[101][201];
    bool solve(int i,int j,string s1, string s2, string s3){
        if(j>= s3.length()) return true;
        if(t[i][j] != -1) return t[i][j];
        bool takes1 = false;
        bool takes2 = false;
        if(s1[i] == s3[j]){
            takes1 = solve(i+1,j+1,s1,s2,s3);
        }    
        if(s2[j-i] == s3[j]){
            takes2 = solve(i,j+1,s1,s2,s3);
        }
        return t[i][j] = takes1 || takes2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        memset(t,-1,sizeof(t));
        return solve(0,0,s1,s2,s3);
    }
};
