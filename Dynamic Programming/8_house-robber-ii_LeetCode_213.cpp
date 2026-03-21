// google amazon microsoft meta bloomberg apple tiktok databricks linkedin uber visa
class Solution {
public:
    int t[101];
    int solve(int i,int n,vector<int>& nums){
        if(i>n) return 0;
        if(t[i] != -1) return t[i];
        int take = nums[i] + solve(i+2,n,nums);
        int skip = solve(i+1,n,nums);
        return t[i] =  max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        memset(t,-1,sizeof(t));
        int ans1 = solve(0,n-2,nums);
        memset(t,-1,sizeof(t));
        int ans2 = solve(1,n-1,nums);
        return max(ans1,ans2);
    }
};
