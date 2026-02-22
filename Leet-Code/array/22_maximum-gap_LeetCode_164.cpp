// google meta amazon microsoft bloomberg
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int maxdiff = 0;
        for(int i = 1;i<n;i++){
            maxdiff = max(maxdiff,nums[i]-nums[i-1]);
        }
        return maxdiff;
    }
};
