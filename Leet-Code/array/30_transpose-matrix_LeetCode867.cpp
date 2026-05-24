// google amazon microsoft meta bloomberg apple 
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int j=0;j<m;j++){
            for(int i =0;i<n;i++){
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};
