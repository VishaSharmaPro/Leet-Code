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
/*
hare and tortoise pehchane ki trick
1 Duplicate
2 Linear Traversal
3 cycle detection
4 entry point in cycle 
*/
