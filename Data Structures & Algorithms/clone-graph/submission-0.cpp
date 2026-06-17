/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        queue<Node*> q;
        unordered_map<Node*,Node*> mp;
        mp[node] = new Node(node->val);
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            // if(vist.find(cur->val)==vist.end()) continue;

            for(auto x:cur->neighbors){
                if(mp.find(x)==mp.end()){
                    mp[x] = new Node(x->val);
                    q.push(x);
                }
                mp[cur]->neighbors.push_back(mp[x]);
            }
        }
        return mp[node];
    }
};











