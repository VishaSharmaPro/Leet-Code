// amazon hive wix microsoft uipath
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    vis[i][j] = true;
                    q.push({i,j});
                } 
            }
        }
        if(q.empty() || q.size() == m * n) return -1;
        int step = -1;
        vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(auto & dir : dirs){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if(ni>=0 && nj>=0 && ni<m && nj<n && vis[ni][nj] == false){
                        q.push({ni,nj});
                        vis[ni][nj] = true;
                    }
                }
            }
            step++;
        }
        return step == 0 ? -1 : step;
    }
};
