// Meta Amazon LTI Mindtree
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> vec = mp[target];
        int n = vec.size();
        int rn = rand() % n;
        return vec[rn];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

/*
other ways of creating random
int r = randomInt(1, 100);
int r2 = rand() % 100;              // 0 se 99 tak
*/
