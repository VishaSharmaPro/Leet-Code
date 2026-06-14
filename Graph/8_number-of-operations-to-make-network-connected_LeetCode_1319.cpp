// google amazon microsoft meta bloomberg phonpe ituit akuna
class Solution {
public:
    vector<int> parent, rank;
    int bonus = 0; // extra cabel;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        if(xp == yp) bonus++;
        if(rank[xp] > rank[yp]){
            parent[yp] = xp;
        }
        else if(rank[xp] < rank[yp]){
            parent[xp] = yp;
        }else{
            parent[xp] = yp;
            rank[yp]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        rank = vector<int>(n,0);
        parent = vector<int>(n,0);
        for(int i=0;i<n;i++) parent[i] = i;
        for(int i=0;i<connections.size();i++){
            Union(connections[i][0],connections[i][1]);
        }
        int unconnected = 0;
        for(int i = 0;i<n;i++){
            if(parent[i] == i) unconnected++;
        }
        int remaining = unconnected-1; // us connect ko minus kardo jo sabka parent hai
        if(bonus >= remaining) return remaining;
        return -1;
    }
};
