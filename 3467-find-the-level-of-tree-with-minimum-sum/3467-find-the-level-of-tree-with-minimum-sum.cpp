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
    int minimumLevel(TreeNode* root) {
        vector<long long> sum;
        sum.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty() ){
            int n = q.size();
            long long currSum = 0;
            for(int i = 0 ; i < n ; i++){
                auto top = q.front();
                q.pop();
                if ( top->left ){
                    q.push(top->left);
                    currSum += top->left->val;
                }
                if ( top->right){
                    q.push(top->right);
                    currSum += top->right->val;
                }
            }
            if ( currSum > 0 ) sum.push_back(currSum);
        }
        int mini = min_element(sum.begin(),sum.end()) - sum.begin();
        return mini + 1;
    }
};