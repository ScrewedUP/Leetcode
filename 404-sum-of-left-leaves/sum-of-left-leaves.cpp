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
    int dfs(TreeNode* root,int where){
        if ( root == NULL ) return NULL;
        int l = dfs(root->left,0);
        if ( l == NULL && where == 0) if ( root->left == NULL && root->right == NULL ) l = root->val;
        int r = dfs(root->right,1);
        return l + r;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if ( root == NULL) return NULL;
        return dfs(root,-1);
    }
};