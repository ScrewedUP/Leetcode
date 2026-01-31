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
    bool ans = true;
    int dfs(TreeNode* root){
        if ( !root ) return 0;
        int l = 1 + dfs(root->left);
        int r = 1 + dfs(root->right);
        if ( abs(l-r) > 1 ) ans = false;
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if ( !root ) return true;
        dfs(root);
        return ans;
    }
};