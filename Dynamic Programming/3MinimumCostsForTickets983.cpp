//Company Tags  : GOOGLE
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int j = i;
        // For 7-day pass
        while(j < days.size() && days[j] < days[i] + 7) j++;
        int cost7 = costs[1] + solve(days, costs, j, dp);

        j = i;
        // For 30-day pass
        while(j < days.size() && days[j] < days[i] + 30) j++;
        int cost30 = costs[2] + solve(days, costs, j, dp);

        // For 1-day pass
        int cost1 = costs[0] + solve(days, costs, i + 1, dp);

        return dp[i] = min({cost1, cost7, cost30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(days, costs, 0, dp);
    }
};
