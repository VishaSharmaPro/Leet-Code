// ggole microsoft amazon apple meta bloomberg yandex uber goldmansachs paypal zoho oracle ituit ibm adobe
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int zeroCount = 0; 
        for(int i = 0;i<n;i++){
            if(nums[i] != 0){
                prod *= nums[i];
            }
            if(nums[i] == 0) zeroCount++; 
        }
        vector<int> ans(n,1);
        if(zeroCount > 1) return vector<int>(n, 0); 
        if(zeroCount == 1){ 
            for(int i = 0;i<n;i++){
                if(nums[i] != 0){
                    nums[i] = 0;
                }else{
                    nums[i] = prod;
                }
            }
            return nums;
        }
        for(int i = 0;i<n;i++){
            if(nums[i] != 0){
                int a = prod/nums[i];
                ans[i] = a;
            }
            else{
                ans[i] = prod;
            }
        }
        return ans;
    }
};
