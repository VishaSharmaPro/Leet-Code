//Company Tags                : Google, Microsoft, Amazon, Ebay, Meta
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return true;
        vector<bool> t(n,false);
        t[0] = true;
        for(int i = 0;i<n;i++){
            if(t[i] == true){
                for(int j=i+1;j<=i+nums[i];j++){
                    t[j] = true;
                    if(j==n-1) return true;
                }
            }
        }
        return false; 
    }
};
