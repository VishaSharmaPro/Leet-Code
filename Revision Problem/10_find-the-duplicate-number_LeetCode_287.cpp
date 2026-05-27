class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow != fast){      // yeh pata lagane ke liye ki konsa elemnt duplicate hai ya cycle ka entry point hai
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
/* yeh vala solution aspect karta hai interviewer
hare and tortoise pehchane ki trick
1 Duplicate
2 Linear Traversal
3 cycle detection
4 entry point in cycle 
*/

// another solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int num = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i-1] == nums[i]){
             num = nums[i];
             break;
            }
        }
        return num;
    }
};
