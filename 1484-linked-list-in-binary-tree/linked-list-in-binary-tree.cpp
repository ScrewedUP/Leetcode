/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(TreeNode*root,ListNode* head,ListNode* head1){
        if ( head == NULL ) return true;
        if ( root == NULL ) return false;
        bool ans = false;
        if ( root->val == head->val ){
            ans |= dfs(root->left,head->next,head1);
            ans |= dfs(root->right,head->next,head1);

        }
        
        
        return ans;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if ( !root ) return false;
        bool ans = dfs(root,head,head);
        ans |= isSubPath(head,root->left) ; 
        ans |= isSubPath(head,root->right) ;
        return ans;
    }
};