// google microsoft amazon bloomber meta apple tiktok adobe zomato yandex zoho visa
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int n = numbers.size();
        int j = n-1;
        while(i<j){
            if(numbers[i] + numbers[j] > target){
                j--;
            }else if(numbers[i] + numbers[j] < target){
                i++;
            }else{
                break;
            }
        }
        return {i+1,j+1};
    }
};
