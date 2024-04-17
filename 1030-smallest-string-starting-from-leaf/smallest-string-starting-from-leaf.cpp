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
    vector<string> ans;
    void dfs(TreeNode* root, string s){
        cout << s << endl;
        if ( root->left == NULL && root->right == NULL){
            s += root->val + 'a';
            string t = s;
            reverse(t.begin(),t.end());
            // cout << t << endl;
            ans.push_back(t);
            return;
        }
        string news = s;
        news += root->val + 'a';
        if ( root->left ) dfs(root->left,news);
        if ( s.size() > 0 ) s.pop_back();
        if ( root->right ) dfs(root->right,news);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        sort(ans.begin(),ans.end());
        bool ok = true;
        if ( ans[0].size() == 1){
            for(int i = 0 ; i < ans.size() ; i++){
                if ( ans[i].size() > 1 ){
                    ok = false;
                    return ans[i];
                }
            }
            if ( ok ) return ans[0];
        }
        
        return ans[0];
    }
};