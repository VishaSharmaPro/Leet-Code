// google amazon microsoft meta phonepe uber bloomberg cisco samsung  goldman 
// top down 
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int id = i;id<=j;id++){
            ans = max(ans, nums[i-1]*nums[id]*nums[j+1] + solve(i,id-1,nums) + solve(id+1,j,nums));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        dp = vector<vector<int>>(n+2,vector<int>(n+2,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return solve(1,n,nums);
    }
};

// Bottom Up
class Solution {
public:
    int n;
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp = vector<vector<int>>(n+2,vector<int>(n+2,0));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        for(int i = n;i>=1;i--){
            for(int j = 1;j<=n;j++){
                if(i>j) continue;
                int ans = 0;
                for(int id = i;id<=j;id++){
                    int cost = nums[i-1]*nums[id]*nums[j+1] + dp[i][id-1] + dp[id+1][j];
                    ans = max(ans,cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};
