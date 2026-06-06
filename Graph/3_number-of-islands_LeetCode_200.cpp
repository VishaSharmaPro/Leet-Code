/* google amazon microsoft meta bloomberg tiktok apple linkedin walmart oracle uber andruil crowdstrike goldman yandex waymo
  bytedance autodesk samsung zoho paypal nvidia adobe tesla wix capitalone meesho
*/
// BFS
class Solution {
public:
    vector<vector<bool>> vis;
    int row , col;
    void bfs(vector<vector<char>>& grid,int r,int c){
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c] = true;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];
                if(nr>=0 && nr<row && nc>=0 && nc<col && vis[nr][nc]==false && grid[nr][nc]=='1'){
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vis = vector<vector<bool>> (row,vector<bool>(col,false));
        int ans = 0;
        for(int r = 0;r<row;r++){
            for(int c = 0;c<col;c++){
                if(vis[r][c] == false && grid[r][c] == '1'){
                    bfs(grid,r,c);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// DFS
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i<0 || i==m || j<0 || j== n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), islands = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};
