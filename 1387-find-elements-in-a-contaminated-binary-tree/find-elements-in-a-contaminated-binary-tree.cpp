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
class FindElements {
public:
    
    unordered_set<int> s;
    void dfs(TreeNode* root,int x){
        if ( !root ) return;
        s.insert(x);
        if ( root->left){
            int k = 2*x + 1;
            dfs(root->left,k);
        }
        if ( root->right){
            int k = 2*x + 2;
            dfs(root->right,k);
        }
    }
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
        if ( s.find(target) != s.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */