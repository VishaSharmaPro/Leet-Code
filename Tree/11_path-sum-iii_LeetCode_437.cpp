// google micrsosft amazon meta bloomberg zepto netapp millennium
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<long long,int> mp;
    int count = 0;
    void solve(long long sum,TreeNode* root, int targetSum){
        if(root == nullptr) return;
        sum += root->val;
        for(auto & it : mp){
            if(sum - it.first == targetSum) count += it.second;
        }
        if(sum == targetSum) count++;
        mp[sum]++;
        solve(sum,root->left,targetSum);
        solve(sum,root->right,targetSum);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        solve(0LL,root,targetSum);
        return count;
    }
};
