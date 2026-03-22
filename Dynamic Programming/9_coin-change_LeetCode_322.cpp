// google amazon microsoft meta bloomberg accolite oracle pinterest ibm infosys datadog uber tiktok paypal goldman apple adobe intuit geico c3.ai mastercard
class Solution {
public:
    int t[13][10001];
    int solve(int i,int sum,vector<int>& coins, int amount){
        if(sum > amount) return amount + 1;
        if(i>=coins.size()) return amount + 1;
        if(sum == amount){
            return 0;
        }
        if(t[i][sum] != -1) return t[i][sum];
        
        int take = amount + 1;
        if(coins[i] <= amount - sum) {  
            take = solve(i, sum + coins[i], coins, amount);
            if(take != amount + 1) take = 1 + take;
        }
        
        int nottake = solve(i+1,sum,coins,amount);
        return t[i][sum] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int ans = solve(0,0,coins,amount);
        return ans > amount ? -1 : ans; 
    }
};
