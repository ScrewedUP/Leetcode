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
    int ans = 0;
    void dfs(TreeNode* root , int val){
        if ( root->left) dfs(root->left,val*10 + root->val);
        if ( root->right) dfs(root->right,val*10 + root->val);
        val = val*10 + root->val;
        if ( root->left == NULL && root->right == NULL){
            ans += val;
        }
        
    }
    int sumNumbers(TreeNode* root) {
        if ( root == NULL ) return ans;
        if ( root->left == NULL && root->right == NULL) return root->val;
        if ( root->left) dfs(root->left,root->val);
        if ( root->right) dfs(root->right,root->val);
        return ans;
    }
};