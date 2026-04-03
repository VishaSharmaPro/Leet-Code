// google amazon mcirosoft meta bloomberg linkedin ibm citadel salesforce yandex goldman apple adobe oracle roku motive
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<n){
            if(nums[j] == 1){
                j++;
            }else{      // 0 hoga
                if(count < k){
                    count++;
                    j++;
                }else{
                    if(nums[i] == 0){
                        count--;
                    }
                    i++;
                }
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};
