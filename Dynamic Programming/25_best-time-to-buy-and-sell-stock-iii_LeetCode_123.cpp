// google amazon microsoft meta bloomberg tiktok tekion apple goldman citadel visa
class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int i,int buy,int count,vector<int>& prices){
        if(i>=n || count >=2) return 0;
        if(dp[i][buy][count] != -1) return dp[i][buy][count];
        int take = 0;
        int skip = 0;
        if(buy == 0){
            take = -prices[i] + solve(i+1,1,count,prices);
            skip = solve(i+1,0,count,prices);
        }else{
            take = prices[i] + solve(i+1,0,count+1,prices);
            skip = solve(i+1,1,count,prices);
        }
        return dp[i][buy][count] = max(take,skip);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,0,0,prices);
    }
};
