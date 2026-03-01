// google amazon microsft apple nvidia meta oracle tiktok paypal bloomberg adobe
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> st;
        int n = nums.size();
        for(int i= 0;i<n;i++){
            st.insert(nums[i]);
        }
        int count = 1;
        int maxcount = 1;
        auto it = st.begin();
        int prev = *it;
        it++;
        for(; it != st.end(); it++){
            if(*it - prev == 1){
                count++;
                maxcount = max(maxcount,count);
            }else{
                count = 1;
                
            }
            prev = *it;
        }
        return maxcount;
    }
};
