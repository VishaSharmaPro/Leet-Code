// google amazon microsoft meta bloomberg capgemini apple cloudflare nvidia yandex doordash linkedin zoho accenture tcs
class Solution {
public:
    int n;
    set<vector<int>> st;
    vector<int> temp;
    unordered_map<string,int> mp;
    vector<vector<int>> ans;
    void solve(int i,long long sum,vector<int>& nums, long long target){
        if(sum == target && temp.size() == 4){
            st.insert(temp);
            return;
        }
        if(i>=n) return;
        if(temp.size() == 4) return;
        if((int)(4-temp.size()) > n-i) return;
        
        temp.push_back(nums[i]);
        
        solve(i+1,sum + nums[i],nums,target);
        temp.pop_back();
        
        while(i+1<n && nums[i+1] == nums[i]) i++;
        solve(i+1,sum,nums,target);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        solve(0,0,nums,target);
        for(auto & it : st) ans.push_back(it);
        return ans;
    }
};
