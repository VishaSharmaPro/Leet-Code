/* google amazon microsoft meta bloomberg amazon apple oracle uber tiktok cloudflare flipkart andruil coupang bytedance rorbolx nordstorm visa ebay linedin
  */
// without topological sort
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    vector<int> vis;  // 0 = unvisited, 1 = visiting, 2 = visited
    
    bool dfs(int node){
        if(vis[node] == 1) return false;  // Cycle detected
        if(vis[node] == 2) return true;   // Already processed
        
        vis[node] = 1;  // Mark as visiting
        
        for(int &ne : mp[node]){
            if(!dfs(ne)) return false;
        }
        
        vis[node] = 2;  // Mark as fully processed
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build graph
        for(auto &preq : prerequisites){
            int u = preq[0];
            int v = preq[1];
            mp[v].push_back(u);  // v -> u (v se pehle u khatam karo)
        }
        
        vis = vector<int>(numCourses, 0);  // 0 = unvisited
        
        // Check for cycle in each component
        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0){
                if(!dfs(i)) return false;
            }
        }
        return true;
    }
};

// with topological sort by BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses);
        vector<int> indegree(numCourses,0);

        for(const auto & prq : prerequisites){
            int course = prq[0];
            int pre_course = prq[1];
            gr[pre_course].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int & ne : gr[curr]){
                indegree[ne]--;
                if(indegree[ne] == 0) q.push(ne);
            }
        }
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};
