// Google amazon microsoft meta apple flipkart samsung bloomberg walmart goldmanSachs qualcoom twitter oracle
class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> dirs{{-1,0},{0,-1},{0,1},{1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if(m<3 || n<3) return 0;
        int water = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i = 0;i<m;i++){
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][n-1],{i,n-1}});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for(int j = 1;j<n-1;j++){
            pq.push({heightMap[0][j],{0,j}});
            pq.push({heightMap[m-1][j],{m-1,j}});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            for(auto & dir : dirs){
                int in = i + dir[0];
                int jn = j + dir[1];
                if(in>=0 && in<m && jn>=0 && jn<n && visited[in][jn] == false){
                    water += max(0,curr.first - heightMap[in][jn]);
                    pq.push({max(curr.first,heightMap[in][jn]),{in,jn}});
                    visited[in][jn] = true;
                }
            }
        }
        return water;
    }
};
