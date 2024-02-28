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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int val;
        while(!q.empty()){
            int n = q.size();
            val = q.front()->val;
            for(int i = 0 ; i < n ; i++){
                auto pointer = q.front();
                q.pop();
                if (pointer->left){
                    q.push(pointer->left);
                }
                if (pointer->right){
                    q.push(pointer->right);
                }
            }
        }
        return val;
    }
};