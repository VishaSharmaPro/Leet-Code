// google amazon microsoft meta goldman 
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> st(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for(int j = 0;j<n;j++){
            st[0][j] = matrix[0][j];
            if(st[0][j] == 1) ans++;
        }
        for(int i = 1;i<m;i++){
            st[i][0] = matrix[i][0];
            if(st[i][0] == 1) ans++;
        }
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j] == 1){
                    st[i][j] = min({st[i-1][j], st[i-1][j-1], st[i][j-1]}) + 1;
                    ans += st[i][j];
                }
            }
        }
        return ans;
    }
};
