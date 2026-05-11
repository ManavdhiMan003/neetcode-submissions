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
    bool fun(TreeNode* root,long left,long right){
        if(root==nullptr) return true;

        if(!(root->val>left and root->val<right)) return false;

        return fun(root->left,left,root->val) and fun(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return fun(root,LONG_MIN,LONG_MAX);
    }
};
