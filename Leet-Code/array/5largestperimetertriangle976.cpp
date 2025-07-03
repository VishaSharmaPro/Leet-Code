class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n =  nums.size();
        sort(begin(nums),end(nums));
        int p = n-3;
        int d = n-2;
        int t = n-1;
        int sum = 0;
        for(int i = n; i>=0;i--){
            if(nums[p]+nums[d] > nums[t]){
                break;
            }
            else if(p == 0){
                return 0;
            }
            else{
                p = p-1;
                d = d-1;
                t = t-1;
            }
        }
        return nums[p] + nums[d] + nums[t];
    }
};
