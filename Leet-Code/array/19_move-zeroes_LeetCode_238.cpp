// Google meta microsoft amazon yandex nvidia qualcomm tiktok LTI Infosys bloomber tcs sigmoid accenture
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(j<n){
            if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i],nums[j]);
                i++;
            }
            if(nums[i] != 0  && nums[j] == 0){
                i++;
                j--;
            }
            j++;
        }
    }
};
