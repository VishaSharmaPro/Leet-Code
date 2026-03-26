// google amazon meta microsoft bloomberg apple morgan tiktok zoho pornhub deshaw
class Solution {
public:
    int t[301][5001];
    int solve(int i,int sum,int amount, vector<int>& coins){
        if(sum == amount) return 1;
        if(i>= coins.size() || sum> amount) return 0;
        if(t[i][sum] != -1) return t[i][sum];
        int take = solve(i,sum + coins[i], amount,coins);
        int skip = solve(i+1,sum,amount,coins);
        return t[i][sum] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(0,0,amount,coins);
    }
};
