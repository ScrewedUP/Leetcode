class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int cur) {
        if (!root) return;

        cur = cur * 2 + root->val;

        if (!root->left && !root->right) {
            ans += cur;
            return;
        }

        dfs(root->left, cur);
        dfs(root->right, cur);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};