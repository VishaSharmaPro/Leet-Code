// google amazon meta microsoft tiktok aetion baidu
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int n = nums.size();
        int i = 0;              
        int j = i+2;
        int ans = 0;
        int count = 0;
        while(j < n){           
            int diff = nums[i+1]-nums[i];
            if(nums[j] - nums[j-1] == diff){  
                count++;          
                ans += count;
                j++;
            }
            else{
                count = 0;
                i = j-1;
                j = i+2;
            }
        }
        return ans;
    }
};
