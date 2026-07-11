class PrefixTree {
private:
    class node{
        public:
            node *nxt[26];
            bool isEnd;
            node(){
                for(auto &x:nxt) x=nullptr;
                isEnd=false;
            }
    };
    node *t;
    
    void insert_help(node* t,string s){
        node *temp = t;
        for(auto x:s){
            
            if(temp->nxt[x-'a']==nullptr) temp->nxt[x-'a'] = new node();

            temp = temp->nxt[x-'a'];
        }
        temp->isEnd = true;
    }
    bool search_help(node* t,string s){
        node* temp = t;
        for(auto x:s){
            if(temp->nxt[x-'a']==nullptr) return false;
            temp = temp->nxt[x-'a'];
        }
        return temp->isEnd;
    }
    bool startswith_help(node *t,string s){
        node* temp = t;
        for(auto x:s){
            if(temp->nxt[x-'a']==nullptr) return false;
            temp = temp->nxt[x-'a'];        
        }
        return true;
    }
public:
    PrefixTree() {
        t = new node();
    }
    
    void insert(string word) {
        insert_help(t,word);
    }
    
    bool search(string word) {
        return search_help(t,word);
    }
    
    bool startsWith(string prefix) {
        return startswith_help(t,prefix);
    }
};
