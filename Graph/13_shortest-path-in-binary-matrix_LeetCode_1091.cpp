// google amazon microsoft meta bloomberg anduril tiktok apple uber goldman databricks airbnb yahoo
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
        pq.push({1,{0,0}});
        vis[0][0] = true;
        int ans = 0;
        while(!pq.empty()){
            int sz = pq.size();
            while(sz--){
                auto curr = pq.top();
                pq.pop();
                int d = curr.first;
                int i = curr.second.first;
                int j = curr.second.second;
                if(i == n-1 && j == n-1) return d;
                
                for(auto & dir : dirs){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    int dist = d + 1;
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] == 0 && !vis[ni][nj]){
                        vis[ni][nj] = true;
                        pq.push({dist,{ni,nj}});
                    }
                }
            }
        }
        return -1;
    }
};
