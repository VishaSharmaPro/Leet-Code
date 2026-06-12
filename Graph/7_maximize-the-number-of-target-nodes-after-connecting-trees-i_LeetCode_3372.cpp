// jio google
class Solution {
public:
    unordered_map<int,vector<int>> mp1;
    unordered_map<int,vector<int>> mp2;
    int maxdegree = 0;
    int find1(int i,int k,int n){
        vector<int> ans;
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(i);
        vis[i] = true;
        int bar = 0;
        int count = 0;
        while(!q.empty() && bar<=k){
            
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                count++;
                for(auto & ne : mp1[curr]){
                    if(!vis[ne]){
                        q.push(ne);
                        vis[ne] = true;
                    }
                }
            }
            bar++;
        }
        return count;
    }
    void finddegree(int i, int k,int m){
        vector<bool> vis(m,false);
        queue<int> q;
        q.push(i);
        vis[i] = true;
        int bar = 0;
        int count = 0;
        while(!q.empty() && bar<=k){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                count++;
                for(auto & ne : mp2[curr]){
                    if(!vis[ne]){
                        q.push(ne);
                        vis[ne] = true;
                    }
                }
                
            }
            bar++;
        }
        maxdegree = max(maxdegree,count);
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        for(auto & edge : edges1){
            int u = edge[0];
            int v = edge[1];
            mp1[u].push_back(v);
            mp1[v].push_back(u);
        }
        for(auto & edge : edges2){
            int u = edge[0];
            int v = edge[1];
            mp2[u].push_back(v);
            mp2[v].push_back(u);
        }
        vector<int> store1(n,0);
        for(int i = 0;i<n;i++){
            store1[i] = find1(i,k,n);
        }
        for(int i = 0;i<m;i++){
            finddegree(i,k-1,m);
        }
        for(int i = 0;i<n;i++){
            store1[i] += maxdegree;
        }
        return store1;
    }
};
