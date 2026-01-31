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
    /*
        stack solution and rec solution
    */
    vector<int> preorderTraversal(TreeNode* root) {
        if ( !root ) return {};
        vector<int> ans;

        // pre order -> Root left right

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            auto tp = s.top();
            s.pop();

            ans.push_back(tp->val);

            if ( tp->right ) s.push(tp->right);
            if ( tp->left ) s.push(tp->left);
        }
        return ans;
    }
    
};