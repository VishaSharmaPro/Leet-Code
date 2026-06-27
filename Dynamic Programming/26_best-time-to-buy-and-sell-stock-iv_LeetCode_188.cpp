// google amazon microsoft meta apple tiktok goldman citadel nielsen hashedin
class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int i,int buy,int count,int k, vector<int>& prices){
        if(i>=n || count>=k) return 0;
        if(dp[i][buy][count] != -1) return dp[i][buy][count];
        int take = 0;
        int skip = 0;
        if(buy == 0){
            take = -prices[i] + solve(i+1,1,count,k,prices);
            skip = solve(i+1,0,count,k,prices);
        }else{
            take = prices[i] + solve(i+1,0,count+1,k,prices);
            skip = solve(i+1,1,count,k,prices);
        }
        return dp[i][buy][count] = max(take,skip);
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return solve(0,0,0,k,prices);
    }
};
