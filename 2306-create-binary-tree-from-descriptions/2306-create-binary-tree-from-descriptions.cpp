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
    void dfs(TreeNode* root,unordered_map<int,vector<pair<int,int>>> &adj){
        if ( root == nullptr) return;

        for(auto it : adj[root->val]){
            int node = it.first;
            if ( it.second == 1 ){
                TreeNode* leftNode = new TreeNode(node);
                root->left = leftNode;
                dfs(root->left,adj);
            }
            else{
                TreeNode* rightNode = new TreeNode(node);
                root->right = rightNode;
                dfs(root->right,adj);
            }
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,vector<pair<int,int>>> adj;
        map<int,int> inD,outD;
        for(auto it : d){
            adj[it[0]].push_back({it[1],it[2]});
            outD[it[0]]++;
            inD[it[1]]++;
        }
        int start = -1;
        for(auto it : d){
            if ( outD.find(it[0]) != outD.end() && inD.find(it[0]) == inD.end()){
                start = it[0];
                break;
            }
        }
        TreeNode* root = new TreeNode(start);
        dfs(root,adj);
        return root;
    }
};