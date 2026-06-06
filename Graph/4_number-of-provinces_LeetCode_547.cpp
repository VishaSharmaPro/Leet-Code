// google amazon microsoft meta bloomberg adobe uber twosigma
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    vector<bool> vi;
    int n;
    void bfs(vector<vector<int>>& isConnected,int node){
        queue<int> q;
        q.push(node);
        vi[node] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int  ne : mp[curr]){
                if(vi[ne] == false){
                    vi[ne] = true;
                    q.push(ne);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vi = vector<bool>(n,false);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<isConnected.size();j++){
                if(i != j && isConnected[i][j] == 1){
                    mp[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int node = 0;node<n;node++){
            if(vi[node] == false){
                bfs(isConnected,node);
                ans++;
            }
        }
        return ans;
    }
};
