/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// google microsoft amazon meta bloomberg tiktok microsoft uber nvidia citadel hive adobe apple workday
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr == NULL){
                    ans += "#,";
                    continue;
                }
                int num = curr->val;
                string s = to_string(num) + ",";
                ans += s;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        vector<string> nodes;
        stringstream ss(data);
        string node;
        while(getline(ss,node,',')){
            if(!node.empty()) nodes.push_back(node);
        }
        if(nodes.empty() || nodes[0] == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i<nodes.size()){
            TreeNode* curr = q.front();
            q.pop();

            if(nodes[i] != "#"){
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;
            if(i<nodes.size() && nodes[i] != "#"){
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
