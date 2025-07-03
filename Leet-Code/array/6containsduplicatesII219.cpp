//Company Tags                : Airbnb, Palantir Technologies
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i =0;i<n;i++){
            int val = nums[i];
            if(mp[val].size()<2){
                mp[val].push_back(i);
            }
            else if(mp[val].size() == 2){
                int p = mp[val][0];
                int q = mp[val][1];
                if((q-p) > (i-q)){
                    mp[val].erase(mp[val].begin());
                    mp[val].push_back(i);
                }
            } 
        }
        for(auto &it : mp){
            int ms = it.second.size();
            if(ms>1 && (it.second[1] - it.second[0]) <= k){
                return true;
            }
        }
        return false;
    }
};
