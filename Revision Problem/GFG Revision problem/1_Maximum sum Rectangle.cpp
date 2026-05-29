// flipkart accolite amazon deshaw factset walmart
class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n =  mat[0].size();
        vector<vector<int>> vec = mat;          // fix: mat se copy karo
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                vec[i][j] = vec[i-1][j] + mat[i][j];
            }
        }
        int maxsum = INT_MIN;
        for(int i =0;i<m;i++){
            for(int j = i;j<m;j++){
                vector<int> colsum(n);
                for(int k = 0;k<n;k++){
                    colsum[k] = vec[j][k] - (i>0 ? vec[i-1][k] : 0);
                }
                int cursum = 0;
                for(int k = 0;k<n;k++){
                    cursum += colsum[k];
                    maxsum = max(maxsum,cursum);
                    if(cursum < 0) cursum = 0;
                }
                
            }
        }
        return maxsum;
    }
};
