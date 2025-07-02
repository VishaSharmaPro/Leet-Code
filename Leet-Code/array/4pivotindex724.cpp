//Amazon, Adobe, Coupang, Radius
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int cumsum = 0;
        int totalsum = 0;
        for(int i = 0;i<n;i++){
            totalsum+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(totalsum - cumsum - nums[i] == cumsum){
                return i;
            }
            else{
                cumsum += nums[i];
            }
        }
        return -1;
    }
};
