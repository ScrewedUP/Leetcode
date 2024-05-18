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
    int dfs(TreeNode* root,int &moves){
        if ( root == nullptr ) return 0;
        int left = 0;
        int right = 0;
        left = dfs(root->left,moves);
        right = dfs(root->right,moves);
        moves += abs(left) + abs(right);
        return left + right - 1 + root->val;

    }
    int distributeCoins(TreeNode* root) {
        int m = 0;
        int moves = dfs(root,m);
        return m;
    }
};