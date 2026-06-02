// google microsoft meta paypal oracle
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                int maxel = target - nums[i] - nums[j];
                int left = j+1, right = n-1;
                int pos = j;
                while(left<= right){
                    int mid = left + (right - left)/2;
                    if(nums[mid] < maxel){
                        pos = mid;
                        left = mid+1;
                    }else{
                        right = mid-1;
                    }
                }
                ans += pos-j;
            }
        }
        return ans;
    }
};
