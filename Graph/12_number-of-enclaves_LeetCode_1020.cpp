// google amazon microsoft meta bloomberg
class Solution {
public:
    vector<vector<bool>> vis;
    int m , n , count = 0;
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    void solve(int i,int j,vector<vector<int>>& grid){
        if(grid[i][j] == 0 || vis[i][j] == true) return;
        vis[i][j] = true;
        if(grid[i][j] == 1) count++;
        for(auto & dir : dirs){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni>= 0 && nj >=0 && ni<m && nj<n && grid[ni][nj] == 1 && !vis[ni][nj]){
                solve(ni,nj,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int j = 0;j<n;j++){
            solve(0,j,grid);
        } 
        for(int j = 0;j<n;j++){
            solve(m-1,j,grid);
        } 
        for(int i = 0;i<m;i++){
            solve(i,0,grid);
        } 
        for(int i = 0;i<m;i++){
            solve(i,n-1,grid);
        } 
        int one = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1) one++;
            }
        }
        return abs(one-count);
    }
};
