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
    int dfs(TreeNode * root , int target){
        if ( root == NULL ) return 0;
        if ( root->left == NULL && root->right == NULL){
            if ( root->val == target) return 1;
            return 0;
        }
        int a = dfs(root->left,target);
        if ( a == 1 ){
            root->left = NULL;
        }
        int b = dfs(root->right,target);
        if ( b == 1 ){
            root->right = NULL;
        }
        if ( root->left == NULL && root->right == NULL && root->val == target){
            return 1;
        }
        return 0;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        int fo = dfs(root,target);
        if ( fo == 1 ) return NULL;
        return root;
    }
};