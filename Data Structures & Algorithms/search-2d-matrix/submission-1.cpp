class Solution {
public:
    bool fun(vector<int> &v,int t){
        int s = 0, e = v.size();
        while(s<=e){
            int m = s + (e-s)/2;
            if(v[m]==t) return true;
            if(v[m]>t) e = m - 1;
            else s = m + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& v, int t) {
        
        int n = v.size();

        int s = 0, e = n-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(v[m][0]==t) return true;
            if(v[m][0]>t){
                e = m - 1;
            }else{
                if(fun(v[m],t)) return true;
                else s = m + 1;
            }
        }
        return false;
    }
};
