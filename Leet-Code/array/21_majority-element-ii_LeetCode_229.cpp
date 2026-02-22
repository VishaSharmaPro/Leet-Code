// company tags = Google microsoft amazon adobe bloomberg atlassian meta intel
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n/3;
        int count = 1;
        vector<int> result;
        sort(begin(nums),end(nums));
        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i-1]){
                count++;
            }
            else{
                if(count > target){
                    result.push_back(nums[i-1]);  
                }
                count = 1;
            }
        }
        if(count>target){
            result.push_back(nums[n-1]);
        }
        return result;
    }
};
