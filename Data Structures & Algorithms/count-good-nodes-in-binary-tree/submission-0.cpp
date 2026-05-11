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
struct data{
    TreeNode* node;
    int mx;
};
public:
    int goodNodes(TreeNode* root) {
        queue<data> q;
        q.push({root,root->val});
        int ans=1;
        while(!q.empty()){
            data nxt = q.front();
            q.pop();
            if(nxt.node->left){
                if(nxt.node->left->val>=nxt.mx){
                    ans++;
                }
                q.push({nxt.node->left,max(nxt.mx,nxt.node->left->val)});
            }
            if(nxt.node->right){
                if(nxt.node->right->val>=nxt.mx){
                    ans++;
                }
                q.push({nxt.node->right,max(nxt.mx,nxt.node->right->val)});
            }
        }
        return ans;
    }
};


//     3
//     /
//     3
//    / \
//    4  2 