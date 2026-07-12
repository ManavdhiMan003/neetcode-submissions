class Trie{
    public:
    Trie* nxt[26];
    bool isEnd;
    Trie(){
        for(auto &x:nxt) x=nullptr;
        isEnd=false;
    }
};
class Solution {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void fun(vector<vector<char>> &v,int x,int y,Trie* root,unordered_set<string> &ans,string s){
        Trie* cur = root->nxt[v[x][y]-'a'];
        int n = v.size();
        int m = v[0].size();
        s+=v[x][y];
        if(cur->isEnd) ans.insert(s);
        char temp = v[x][y];
        v[x][y] = '*';
        // cout<<x<<" "<<y<<" "<<s<<endl;
        for(int z=0;z<4;z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            if(cx>=0 and cx<n and cy>=0 and cy<m and v[cx][cy]!='*' and cur->nxt[v[cx][cy]-'a']!=nullptr){
                fun(v,cx,cy,cur,ans,s);
            }
        }
        v[x][y] = temp;
        s.pop_back();
    }
    void insert(Trie *root,string s){
        Trie* cur = root;
        for(auto &x:s){
            if(cur->nxt[x-'a']==nullptr) cur->nxt[x-'a']=new Trie();
            cur = cur->nxt[x-'a'];
        }
        cur->isEnd=true;
    }
public:
    vector<string> findWords(vector<vector<char>>& v, vector<string>& words) {
        unordered_set<string> ans;
        int n = v.size();
        int m = v[0].size();

        bool flg = false;
        Trie* root = new Trie();
        for(auto &x:words){
            insert(root,x);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c = v[i][j];
                if(root->nxt[c-'a']!=nullptr){
                    fun(v,i,j,root,ans,"");
                }
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};
