//Company Tags : Amazon, Meta, Google
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result;
        int j = 0;
        for(int i = 0;i<n;i++){
            int bit = nums[i][j] - '0';
            if(bit == 1) result += '0';
            else result += '1';
            j++;
        }
        return result;
    }
};
