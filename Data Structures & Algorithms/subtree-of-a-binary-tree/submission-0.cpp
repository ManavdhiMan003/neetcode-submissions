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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;

        if(p and q and p->val==q->val){
            return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr and subRoot==nullptr) return true;
        if(subRoot==nullptr or root==nullptr) return false;
        
        // cout<<root->val<<" "<<subRoot->val<<endl;
        if(root->val==subRoot->val){
            if(isSameTree(root,subRoot)){
                // cout<<"dammn"<<endl;
                return true;
            }
        }  

        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);

    }
};
