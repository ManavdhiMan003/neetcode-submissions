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
    bool bal;
    int fun(TreeNode* root){
        if(root==nullptr) return 0;
        int hl=0,hr=0;
        if(root->left) hl = fun(root->left)+1;
        if(root->right) hr = fun(root->right)+1;

        if(abs(hl-hr)>1) bal=false;
        return max(hl,hr);

    }
public:
    bool isBalanced(TreeNode* root) {
        bal=true;
        fun(root);
        return bal;
    }
};
