// ggole amazon microsoft meta bloomberg linkedin apple tiktok oracle goldman flipkart morgan zoho servicenow avito walamrt spotify bytedance
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            pq.push(nums[i]);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
