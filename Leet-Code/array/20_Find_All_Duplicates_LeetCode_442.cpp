// Google microsoft apple meta oracle yahoo tiktok bloomberg
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> result;
        for(auto & it : mp){
            int val = it.first;
            int freq = it.second;
            if(freq>1) result.push_back(val);
        }
        return result;
    }
};
