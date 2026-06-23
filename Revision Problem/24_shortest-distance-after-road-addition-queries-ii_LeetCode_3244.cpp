class Solution {
public:
    void remove(set<int> &set,int l,int r){
        auto it = set.upper_bound(l);
        while(it != set.end() && *it<r){
            it = set.erase(it);
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        set<int> set;
        for(int i = 0;i<n;i++){
            set.insert(i);
        }
        vector<int> ans;
        for(auto & m : queries){
            int l = m[0];
            int r = m[1];
            remove(set,l,r);
            ans.push_back(set.size()-1);
        }
        return ans;
    }
};
