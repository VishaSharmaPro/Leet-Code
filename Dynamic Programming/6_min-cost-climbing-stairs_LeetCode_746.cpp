// google amazon microsoft meta bloomberg
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t(n+1,0);
        t[0] = cost[0];
        t[1] = cost[1];
        for(int i = 2;i<n;i++){
            t[i] = cost[i] + min(t[i-1],t[i-2]);
        }
        return min(t[n-1],t[n-2]);
    }
};
