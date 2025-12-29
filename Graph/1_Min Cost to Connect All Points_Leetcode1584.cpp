// Company Tags  : META, amazon , google, microsoft , uber , tiktok, bloomberg, directi
class Solution {
public:
    typedef pair<int,int> p;
    int PrimsAlgo(unordered_map<int,vector<p>> &adj,int V){
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<bool> inMST(V,false);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto pair = pq.top();
            int w = pair.first;
            int nd = pair.second;
            pq.pop();
            if(inMST[nd] == true) continue;
            inMST[nd] = true;
            sum += w;
            for(auto & edge : adj[nd]){
                int ng = edge.first;
                int ngw = edge.second;
                if(inMST[ng] == false){
                    pq.push({ngw,ng});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        unordered_map<int,vector<p>> adj;
        for(int u = 0;u<V;u++){
            for(int v = u+1;v<V;v++){
                int x1 = points[u][0];
                int y1 = points[u][1];
                int x2 = points[v][0];
                int y2 = points[v][1];
                int d = abs(x1 - x2) + abs(y1-y2);
                adj[u].push_back({v,d});
                adj[v].push_back({u,d});
            }
        }
        return PrimsAlgo(adj,V);
    }
};
