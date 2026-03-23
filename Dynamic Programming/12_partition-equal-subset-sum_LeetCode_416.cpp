// google amazon meta bloomberg microsoft tiktok zoho epam goldman dream11 flipkart walmart ebay visa
class Solution {
public:
    int t[200][20001];
    int total;
    bool solve(int i,int sum1,vector<int>& nums){
        if(i>=nums.size()) return sum1 == total- sum1;
        if(t[i][sum1] != -1) return t[i][sum1];
        bool take = solve(i+1,sum1 + nums[i],nums);
        bool skip = solve(i+1,sum1,nums);
        return t[i][sum1] = (take || skip);
    }
    bool canPartition(vector<int>& nums) {
        total = 0;
        for(int i = 0;i<nums.size();i++){
            total += nums[i];
        }
        if(total%2 != 0) return false;
        memset(t,-1,sizeof(t));
        return solve(0,0,nums);
    }
};
