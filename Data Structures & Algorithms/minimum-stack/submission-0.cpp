class MinStack {
private:
    vector<int> st,mn;
    int len=1e6;
    int id;    
public:
    MinStack() {
        st.resize(len,-1);
        id=0;
    }
    
    void push(int val) {
        st[id++]=val;
        if(mn.size()==0){
            mn.push_back(val);
        }else if(mn[mn.size()-1]>=val) mn.push_back(val);
        // cout<<"push"<<" -> "<<id<<" "<<st[id-1]<<" "<<mn[mn.size()-1]<<endl;

    }
    
    void pop() {
        if(id==0) return;
        if(mn[mn.size()-1]==st[id-1]) mn.pop_back();
        id--;
        // cout<<"pop"<<" -> "<<id<<" "<<st[id]<<" "<<mn[mn.size()-1]<<endl;

    }
    
    int top() {
        // cout<<"top"<<" -> "<<id<<" "<<st[id]<<" "<<mn[mn.size()-1]<<endl;
        return st[id-1];
    }
    
    int getMin() {
        // cout<<"min"<<" -> "<<id<<" "<<st[id]<<" "<<mn[mn.size()-1]<<endl;

        return mn[mn.size()-1];
    }
};
