// Company Tags                : Indeed (Frequently Asked)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        int ns = nums.size();
        for(int i =0;i<ns;i++){
            if(nums[i]%2 == 0){
                sum += nums[i];
            }
        }
        int qs = queries.size();
        vector<int> result;
        for(int i =0;i<qs;i++){
            int value = queries[i][0];
            int index = queries[i][1];
            if(nums[index]%2 != 0){
                nums[index] += value;
                if(nums[index]%2 == 0){
                    sum += nums[index];
                }
            }else{
                sum -= nums[index];
                nums[index] += value;
                if(nums[index]%2 == 0){
                    sum+=nums[index];
                }
            }
            result.push_back(sum);
        }
        return result;
    }
};
