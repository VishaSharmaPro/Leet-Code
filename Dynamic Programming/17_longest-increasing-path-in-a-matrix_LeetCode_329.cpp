// google meta amazon microsoft apple doordash duolingo tiktok uber nutanix adobe phonepe weride
// pura question khud se kiya within 25min ek word tak nhi dekha claude deepseek se
class Solution {
public:
    int ans = 0;
    int m, n ;
    int t[201][201];
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(t[i][j] != -1) return t[i][j];
        int left = 0;
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]){
            left = 1 + solve(i,j-1,matrix);
        }
        int right = 0;
        if(j+1 < n && matrix[i][j+1] > matrix[i][j]){
            right = 1 + solve(i,j+1,matrix);
        }
        int up = 0;
        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]){
            up = 1 + solve(i-1,j,matrix);
        }
        int down = 0;
        if(i+1 < m && matrix[i+1][j] > matrix[i][j]){
            down = 1 + solve(i+1,j,matrix);
        }
        return t[i][j] = max({left,right,up,down});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(t,-1,sizeof(t));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }
        return ans+1;
    }
};
