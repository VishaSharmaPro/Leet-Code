// google amazon microsoft meta bloomberg paypal tiktok block oracle samsung walamrt spunk yandex uber goldman ituit autodesk
class Solution {
public:
    int t[2501][2501];
    int solve(int i,int prev,vector<int>& nums){
        if(i>=nums.size()) return 0;
        if(t[i][prev+1] != -1) return t[i][prev+1];
        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]){
            take = 1 + solve(i+1,i,nums);
        }
        int skip = solve(i+1,prev,nums);
        return t[i][prev+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};
