// google amazon microsoft meta bloomberg
class DSU{
public:
vector<int> parent,rank;
    DSU(int n){
        parent = vector<int> (n,0);
        rank = vector<int> (n,0);

        for(int i = 0;i<n;i++) parent[i] = i;
    }
    int findnodes(int i){
        return parent[i] = (parent[i] == i) ? i : findnodes(parent[i]);
    }
    bool unionodes(int x,int y){
        int x_parent = findnodes(x);
        int y_parent = findnodes(y);
        if(x_parent != y_parent){
            if(rank[x_parent] > rank[y_parent]) parent[y_parent] = x_parent;
            else if(rank[x_parent] < rank[y_parent]) parent[x_parent] = y_parent;
            else{
                parent[x_parent] = y_parent;
                rank[y_parent]++;
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            dsu.unionodes(u,v);
        }
        return dsu.findnodes(source) == dsu.findnodes(destination);
    }
};
