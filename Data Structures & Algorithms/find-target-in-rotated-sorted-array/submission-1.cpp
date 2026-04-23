class Solution {
private:

    int find_index(vector<int> &v){
        int s = 0, e = v.size()-1;
        int n = v.size();
        if(v[0]<v[e]) return 0;
        if(n==1) return 0;
        if(v[e]<v[e-1] and v[e]<v[0]) return e;
        while(s<=e){
            int m = s + (e-s)/2;
            // cout<<v[m]<<" "<<m<<endl;
            if(v[m]<v[m-1] and v[m]<v[m+1]) return m;
            if(v[m]>v[e]) s = m+1;
            else e=m-1;
        }
        return -1;
    }
    int bs(vector<int> &v,int s,int e,int t){
        // cout<<s<<" -> "<<e<<endl;
        while(s<=e){
            int m = s + (e-s)/2;
            // cout<<m<<" "<<v[m]<<endl;
            if(v[m]==t) return m;
            if(v[m]>t) e = m-1;
            else s = m+1;
        }
        return -1;
    }
public:
    int search(vector<int>& v, int t) {
        int n = v.size();
        int x = find_index(v);
        // cout<<x<<endl;
        int first = bs(v,0,x,t);
        int second = bs(v,x,n-1,t);
    
        // cout<<first<<" "<<second<<endl;
        if(first!=-1) return first;
        if(second!=-1) return second;
        return -1;
    }
};


