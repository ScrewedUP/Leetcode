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
        3 solutions
        1) Rec - Done
        2) 2 stacks
        3) 1 stack
    */
    vector<int> postorderTraversal(TreeNode* root) {
        /*

            Algo -> Take 2 stacks , add the root to the first stack 
            not till stack is empty do this
            pop the top element , put that in stack2 
            if the top element has left put left one in stack 
            if it has right put the right one , after that the stack2
            will be the answer
        */

        if ( !root ) return {};
        vector<int> ans;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            auto tp = s1.top();
            s1.pop();
            s2.push(tp);

            if ( tp->left){
                s1.push(tp->left);
            }
            if ( tp->right){
                s1.push(tp->right);
            }
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};