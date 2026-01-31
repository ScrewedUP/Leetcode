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
    int maxDepth(TreeNode* root) {
        if ( !root ) return 0;

        queue<TreeNode*> q;
        int height = 0;
        q.push(root);
        while(!q.empty()){
            height++;
            int x = q.size();
            for(int i = 0 ; i < x ; i++){
                auto tp = q.front();
                q.pop();
                if ( tp->left ) q.push(tp->left);
                if ( tp->right) q.push(tp->right);
            }
        }
        return height;
    }
};