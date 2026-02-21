// Meta Google , Amazon, Bloomberg , Turing
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum  = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            sum += arr[i];
        }
        if (sum % 3 != 0) return false;
        int target = sum/3;
        int x = 0;
        int count = 0;
        for(int i = 0;i<n;i++){
            x += arr[i];
            if(x == target) {
                count++;
                x = 0;
            }
        }
        if(count >= 3) return true;
        else return false;
    }
};
