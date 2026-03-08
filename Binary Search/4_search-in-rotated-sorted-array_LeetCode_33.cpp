// amazon google microsoft meta bloomberg linkeidn grammarlytiktok paypal oracle yandex goldman apple walmart uber flipkart zoho autodesk nvidia newsbreak
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid;
        while(s<=e){
            mid = s +(e-s)/2;
            if(nums[mid] == target) return mid;
            if(nums[s] <= nums[mid]){
                if(nums[mid] > target && target < nums[s]){
                    s = mid +1;
                }else if(nums[mid] < target && target <= nums[e]){
                    s = mid+1;
                }
                else if(mid +1 <n &&nums[mid] < target && nums[mid] < nums[mid + 1]){
                    s = mid +1;
                }
                else{
                    e = mid-1;
                }
            }else{
                if(target <= nums[e] && nums[mid] >= target){
                    e = mid-1;
                }
                else if(target >= nums[mid] && target >= nums[s]){
                    e = mid-1;
                }
                else{
                    s = mid +1;
                }
            }
        }
        return -1;
    }
};
