// google amazon microsoft tiktok oracle bloomberg snap sprinkler otter.ai
class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int t[2001][2001];
    bool solve(vector<int>& stones,int i,int j){
        if(i==n-1) return true;
        if(j<=0 || j>2000) return false;
        if(t[i][j] != -1) return t[i][j];
        bool first = false, second = false, third = false;
        if(mp.find(stones[i] + j -1) != mp.end())
            first = solve(stones,mp[stones[i] + j-1],j-1);
        if(mp.find(stones[i] + j) != mp.end())
            second = solve(stones,mp[stones[i] + j],j);
        if(mp.find(stones[i] + j +1) != mp.end())
            third = solve(stones,mp[stones[i] + j+1],j+1);
        return t[i][j] = first || second || third;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1] != 1) return false;
        memset(t,-1,sizeof(t));
        for(int i = 0;i<n;i++){
            mp[stones[i]] = i;
        }
        return solve(stones,1,1); // 0→1 se shuru, i=1,j=1
    }
};
