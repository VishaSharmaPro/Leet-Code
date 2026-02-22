// amazon google meta bloomberg makemytrip adobe oracle apple sevicenow zomato myntra netfix 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int m = nums[0];
        for(int i = 0;i<n;i++){
            m = max(nums[i],m);
        }
        if(m <= 0) return 1;        
        m = min(m, n);
        vector<int> store(m+2, 0);
        for(int i = 0;i<n;i++){
            if(nums[i]>0 && nums[i]<=m) {
                int id = nums[i];
                store[id] = 1;
            }
        }
        int ans = 1;
        for(int i = 1;i<=m;i++){
            if(store[i] == 0){
                ans = i;
                break;
            }
        }
        if(ans == 1 && store[1] == 1) ans = m+1;
        return ans;
    }
};
