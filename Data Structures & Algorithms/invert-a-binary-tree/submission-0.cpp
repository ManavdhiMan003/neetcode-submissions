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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* n = st.top();
            st.pop();
            if(n->left) st.push(n->left);
            if(n->right) st.push(n->right);

            TreeNode* temp = n->left;
            n->left=n->right;
            n->right=temp;
        }
        return root;

    }
};
