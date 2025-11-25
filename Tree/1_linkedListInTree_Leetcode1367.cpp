class Solution {
public:
    bool ans = false;
    
    void solve(ListNode* head, TreeNode* root, int count) {
        if(root == NULL) return;
        if(ans) return;  
        if(head->val == root->val) {
            if(head->next == NULL) {
                ans = true; 
                return;
            }
            if(root->left != nullptr && head->next->val == root->left->val) {
                solve(head->next, root->left, count + 1);
            }
            if(root->right != nullptr && head->next->val == root->right->val) {
                solve(head->next, root->right, count + 1);
            }
        }
        if(count == 0){
            solve(head, root->left, 0);
            solve(head, root->right, 0);
        } 
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        int count = 0;
        solve(head, root, count);
        return ans;
    }
};
