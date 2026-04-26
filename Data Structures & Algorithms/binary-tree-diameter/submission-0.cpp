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
private:
    int mx;
    int fun(TreeNode* root){
        if(root==nullptr) return 0;

        int l=0,r=0;
        if(root->left) l = fun(root->left)+1;
        if(root->right) r = fun(root->right)+1;
        cout<<root->val<<" "<<l<<" "<<r<<endl;
        mx = max(mx,l+r);
        return max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        mx=0;
        fun(root);
        return mx;
    }
};


// r + l + r