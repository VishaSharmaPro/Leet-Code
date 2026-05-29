// google amazon microsoft meta amazon bloomberg apple linkedin adobe
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
class BSTIterator {
public:
    vector<int> vec;
    void solve(TreeNode* root){
        if(root == NULL) return;
        solve(root->left);
        vec.push_back(root->val);
        solve(root->right);
    }
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    int i = 0;
    int next() {
        int ans = vec[i];
        i++;
        return ans;
    }
    
    bool hasNext() {
        return i - vec.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
