// google amazon microsoft 
class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    int bfs(int n){
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                if(curr == n-1) return ans;
                q.pop();
                for(auto & ne : mp[curr]){
                    int el = ne.first;
                    if(!vis[el]){
                        vis[el] = true;
                        q.push(el);
                    }
                }   
            }
            ans++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        mp[0].push_back({1,1});
        for(int i = 1;i<n;i++){
            mp[i].push_back({i+1,1});
        }
        vector<int> ans;
        
        for(auto & qe :queries){
            int u = qe[0];
            int v = qe[1];
            mp[u].push_back({v,1});
            int shortest = bfs(n);
            ans.push_back(shortest);
        }
        return ans;
    }
};
