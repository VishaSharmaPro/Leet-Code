// google amazon microsoft apple goldman aqr tiktok
class Solution {
public:
    int t[50001][2];
    int solve(int i,int flag,vector<int>& prices){
        if(i>= prices.size()) return 0;
        if(t[i][flag] != -1){
            return t[i][flag];
        }
        int buy = 0;
        if(flag == 1){
            buy = -prices[i] + solve(i+1,0,prices);
        }
        int sell = 0;
        if(flag == 0){
            sell = prices[i] + solve(i+2,1,prices);
        }
        int skip = solve(i+1,flag,prices);
        return t[i][flag] =  max({skip,buy,sell});
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(0,1,prices);
    }
};
