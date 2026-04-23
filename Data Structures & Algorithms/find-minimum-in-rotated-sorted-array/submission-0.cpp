class Solution {
public:
    int findMin(vector<int> &v) {
        int n = v.size();
        if(n==1) return v[0];
        if(v[0]<v[n-1]) return v[0];
        if(v[n-1]<v[n-2] and v[n-1]<v[0]) return v[n-1];
        int s = 0, e = n-1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(v[m]<v[m-1] and v[m]<v[m+1]) return v[m];
            if(v[m]>v[e]){
                s = m+1;
            }else {
                e = m-1;
            }
        }
        return -1;
    }
};


// rotated point


// x--m----y

// y>x x hi answer

// m>y
// ->

// m<y