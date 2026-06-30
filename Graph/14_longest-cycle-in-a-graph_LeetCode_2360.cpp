// google amazon microsoft andruil juspay phonepe
class Solution {
public:
    int n;
    vector<bool> vis;
    vector<bool> path;
    unordered_map<int,int> mp;
    unordered_map<int,int> position;

    int dfs(int node){
        int nx = mp[node];
        if(nx == -1) return -1;

        if(path[nx] == true){          
            return position[node] - position[nx] + 1;
        }

        if(!vis[nx]){
            vis[nx] = true;
            path[nx] = true;
            position[nx] = position[node] + 1;
            int res = dfs(nx);
            path[nx] = false;          
            return res;
        }

        return -1;  
    }

    int longestCycle(vector<int>& edges) {
        n = edges.size();
        
        for(int i = 0; i < n; i++){
            mp[i] = edges[i];
        }

        int ans = -1;
        vis = vector<bool>(n, false);
        path = vector<bool>(n, false);  

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vis[i] = true;
                path[i] = true;
                position[i] = 1;
                int longCycleInCompo = dfs(i);
                ans = max(longCycleInCompo, ans);
                path[i] = false;       
            }
        }
        return ans;  
    }
};
