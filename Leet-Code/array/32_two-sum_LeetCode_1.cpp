/*
Google (158), Amazon (80), Meta (31), Microsoft (29), Bloomberg (22), TCS (8), Infosys (4), Capgemini (3), Apple (2), Cognizant (2), Deloitte (6), Oracle (5), eBay (5), NetApp (5), JPMorgan Chase (4), IBM (4), Nvidia (3), Visa (3), Accenture (3), Adobe (2), Yandex (18), Zoho (16), SAP (14), EPAM Systems (13), TikTok (13), Goldman Sachs (13), Walmart Labs (11), Wipro (9), Spotify (8), HubSpot.
  */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        int i = 0,j=n-1;
        vector<int> ans;
        while(i<j){
            if(nums[i] + nums[j] == target){
                if(nums[i] == nums[j]){
                    ans.push_back(mp[nums[i]][0]);
                    ans.push_back(mp[nums[j]][1]);
                }
                else{
                    ans.push_back(mp[nums[i]][0]);
                    ans.push_back(mp[nums[j]][0]);
                }
                break;
            } 
            int sum = nums[i] + nums[j];
            if(sum>target){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};
