/* google amazon microsoft meta bloomberg tiktok apple linkedin walmart oracle uber andruil crowdstrike goldman yandex waymo
  bytedance autodesk samsung zoho paypal nvidia adobe tesla wix capitalone meesho
*/
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
