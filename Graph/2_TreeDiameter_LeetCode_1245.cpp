// company tags = Meta , Amazon , Google , Apple , TikTok
class Solution {
public:
    int fn;
    int d;
    void BFS(unordered_map<int,vector<int>> adj,int x,int n){
        queue<int> q;
        q.push(x);
        vector<bool> visited(n,false);
        vector<int> dist(n,0);
        visited[x] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto & vec : adj[curr]){
                if(visited[vec] == false){
                    visited[vec] = true;
                    q.push(vec);
                    dist[vec] = dist[curr] + 1;
                    if(dist[vec]>d){
                        d = dist[vec];
                        fn = vec;
                    }
                }
            }
        }
    }
    int treeDiameter(vector<vector<int>>& edges) {
        if(edges.empty()) return 0;
        unordered_map<int,vector<int>> adj;
        int n = 0;
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            n = max(n,max(u,v));
        }
        n++;
        d = 0;
        int x = edges[0][0];
        BFS(adj,x,n);
        d = 0;
        BFS(adj,fn,n);
        return d;
    }
};
