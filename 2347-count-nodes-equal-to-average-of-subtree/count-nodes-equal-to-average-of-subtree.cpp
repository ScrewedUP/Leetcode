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
    int cnt = 0;
    pair<int,int> dfs(TreeNode* root,int nodes){
        if ( !root ) return {0,0};

        pair<int,int> leftSum = dfs(root->left,nodes+1);
        pair<int,int> rightSum = dfs(root->right,nodes+1);

        int nc = leftSum.second + rightSum.second + 1;
        int sum = leftSum.first + rightSum.first + root->val;

        if ( sum/nc == root->val) cnt++;
        return {sum,nc};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root,0);
        return cnt;
    }
};