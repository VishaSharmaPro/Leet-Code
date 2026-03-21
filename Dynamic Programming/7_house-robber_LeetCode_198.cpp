// google amazon micrososft meta bloomberg expedia nvidia walmart gusto cisco databrciks uber adobe deshaw linkedin orace datadog phonpe bytedance goldman tiktok
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums,int i){
        if(i>=nums.size()) return 0;
        if(t[i] != -1) return t[i];
        int take = nums[i] + solve(nums,i+2);
        int skip = solve(nums,i+1);
        return t[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0);
    }
};

// bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> t(n,0);
        t[0] = nums[0];
        t[1] = nums[1];
        t[2] = nums[2] + nums[0];
        for(int i = 3;i<n;i++){
            t[i] = nums[i] + max(t[i-2],t[i-3]);
        }
        return max(t[n-1],t[n-2]);
    }
};
