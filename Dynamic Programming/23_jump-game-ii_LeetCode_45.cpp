// google amazon microsoft meta bloomberg zulily  ebay tiktok zoho phonepay tcs adobe oracle atlassain hashedin
class Solution {
public:
    int n;
    long long t[10001];
    long long solve(int i,vector<int>& nums){
        if(i == n-1) return 0;
        if(i>=n) return INT_MAX;
        if(t[i] != -1) return t[i];
        long long jump = INT_MAX;
        for(int j = 1;j<=nums[i];j++){
            jump = min(jump, 1 + solve(i+j,nums));
        }
        return t[i] = jump;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};
