// google amazon microsoft meta bloomberg goldman tiktok apple uber yandex oracle flipkart
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid;
        while(s<=e){
            mid = s + (e-s)/2;
            if(mid-1 >=0 && mid+1 <n && nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid]){
                return nums[mid];
            }
            if(nums[mid] <= nums[e]){
                e = mid-1;
            }
            else if(nums[mid] > nums[e]){
                s =mid+1;
            }
            
        }
        return nums[s];
    }
};
