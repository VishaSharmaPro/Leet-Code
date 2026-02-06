//company tags = IBM, Google, Amazon, Meta, Bloomberg, Zomato
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        vector<int> suffix(n,0);
        suffix[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i = n-2;i>=0;i--){
            suffix[i] = nums[i] + suffix[i+1];
        }
        vector<int> vec(n,0);
        for(int i = 0;i<n;i++){
            if(i>0){
                vec[i] += abs(prefix[i-1] - (nums[i]*i));
            }
            if(i<n-1){
               vec[i] += abs(suffix[i+1]) - nums[i]*(n-1-i);
            }
           
        }
        return vec;
    }
};
