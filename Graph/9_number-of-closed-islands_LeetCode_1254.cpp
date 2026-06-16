// google amazon microsoft meta oracle
class Solution {
public:
    int m, n;
    bool dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=m || j>=n) return false; 
        if(grid[i][j] == 1) return true;
        grid[i][j] = 1;
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        bool closed = true;
        for(auto & dir : dirs){
            int in = i + dir[0];
            int jn = j + dir[1];
            if(!dfs(in,jn,grid)) closed = false;
        }
        return closed; 
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i = 1;i<m-1;i++){
            for(int j = 1;j<n-1;j++){
                if(grid[i][j] == 0){
                    if(dfs(i,j,grid)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
