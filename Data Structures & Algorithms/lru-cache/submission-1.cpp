class LRUCache {
private:
class doubleLinkedList{
    public:
    doubleLinkedList* prev;
    doubleLinkedList* next;
    int val;int key;
    doubleLinkedList(){
        prev=nullptr;
        next=nullptr;
        val=0;
        key=0;
    }
    doubleLinkedList(int v){
        prev=nullptr;
        next=nullptr;
        val=v;
        key=0;
    }
};

int cap;
doubleLinkedList* head;
doubleLinkedList* tail;
unordered_map<int,doubleLinkedList*> mp;
int sz;

void insert(doubleLinkedList *n){
        doubleLinkedList* prev=head->prev;
        prev->next=n;
        n->prev=prev;
        n->next=head;
        head->prev=n;
    }
    void remove(doubleLinkedList *n){
        doubleLinkedList* prev = n->prev;
        doubleLinkedList* nxt = n->next;
        prev->next = nxt;
        nxt->prev=prev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head=new doubleLinkedList(0);
        tail=new doubleLinkedList(0);
        head->prev=tail;
        tail->next=head;
        mp.clear();
        sz=0;
    }
    
    
    int get(int key) {

        if(mp.find(key)==mp.end()) return -1;

        doubleLinkedList* node = mp[key];
        remove(node);
        insert(node);
        return node->val;

    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            remove(mp[key]);
        }
        doubleLinkedList* node = new doubleLinkedList(value);
        node->key=key;
        mp[key]=node;
        insert(node);
        if(mp.size()>cap){
            doubleLinkedList* temp = tail->next;
            remove(temp);
            mp.erase(temp->key);
            delete temp;
        }
    }
};
