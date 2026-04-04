// google amazon bloomberg meta microsoft walmart nvidia
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long sum = 0;
        long long crsum = 0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            crsum += nums[j];
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                crsum -= nums[i];
                i++;
            }
            
            while(mp[nums[j]] > 1){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                crsum -= nums[i];
                i++;
            }
            if(mp.size() == k){
                sum = max(sum,crsum);
            }
            j++;
        }
        return sum;
    }
};
