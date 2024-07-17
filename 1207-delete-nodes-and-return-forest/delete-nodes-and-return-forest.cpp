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
    TreeNode* dfs(TreeNode* root, set<int> &to_delete_set, vector<TreeNode*> &ans) {
        if (root == nullptr) return nullptr;

        root->left = dfs(root->left, to_delete_set, ans);
        root->right = dfs(root->right, to_delete_set, ans);

        if (to_delete_set.find(root->val) != to_delete_set.end()) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            delete root;
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        set<int> to_delete_set(to_delete.begin(), to_delete.end());
        
        if (dfs(root, to_delete_set, ans) != nullptr) {
            ans.push_back(root);
        }
        
        return ans;
    }
};
