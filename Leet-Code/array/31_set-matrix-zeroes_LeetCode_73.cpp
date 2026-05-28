// google amazon microsoft meta bloomberg apple orcle tcs goldmanebay walmart jpmorgan juspay
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        
        int n = matrix[0].size();     
        
        unordered_map<string, pair<int,int>> mp;    
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    string key = to_string(i) + "_" + to_string(j); 
                    mp[key] = {i, j};
                }
            }
        }
        
        for(auto & it : mp) {
            int row = it.second.first;   
            int col = it.second.second;  
            
            for(int x = 0; x < n; x++) {
                matrix[row][x] = 0;
            }
            
            for(int x = 0; x < m; x++) {
                matrix[x][col] = 0;
            }
        }
    }
};
