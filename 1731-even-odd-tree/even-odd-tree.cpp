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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if ( root->val % 2 == 0 ) return false;
        int cnt = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> ans;
            for(int i = 0 ; i < n ; i++){
                auto pointer = q.front();
                q.pop();
                if ( pointer->left){
                    q.push(pointer->left);
                    ans.push_back(pointer->left->val);
                }
                if ( pointer->right){
                    q.push(pointer->right);
                    ans.push_back(pointer->right->val);
                }
            }
            if ( cnt & 1 ){
                //Decreasing and even
                for(int i = 0 ; i < ans.size() ; i++){
                    if ( ans[i] & 1 ) return false;
                }
                for(int i = 1 ; i < ans.size() ; i++){
                    if ( ans[i] >= ans[i-1] ) return false;
                }
            }
            else if ( cnt % 2 == 0 ){
                //Increasing and odd
                for(int i = 0 ; i < ans.size() ; i++){
                    if ( ans[i] % 2 == 0 ) return false;
                }
                for(int i = 1 ; i < ans.size() ; i++){
                    if ( ans[i] <= ans[i-1] ) return false;
                }
            }
            cnt++;
        }
        return true;
    }
};