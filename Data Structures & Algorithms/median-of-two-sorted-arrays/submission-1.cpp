class Solution {
public:
    double fun(vector<int> &a,vector<int> &b){
        int n=a.size();
        int m=b.size();
        int sz = n+m;
        int hf = (sz+1)/2;
        int s = 0,e=n;
        while(s<=e){
            int i = s+(e-s)/2;
            int j = hf - i;

            int Aleft = i>0?a[i-1]:INT_MIN;
            int Aright = i<a.size()?a[i]:INT_MAX;
            int Bleft = j>0?b[j-1]:INT_MIN;
            int Bright = j<b.size()?b[j]:INT_MAX;

            if(Aleft<=Bright and Bleft<=Aright){
                if(sz%2){
                    return max(Aleft,Bleft);
                }else{
                    return (max(Aleft,Bleft)+min(Aright,Bright))/2.0;
                }
            }
            else if(Aleft>Bright){
                e = i-1;
            }else s = i+1;

        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        if(n>m){
            return fun(b,a);
        }
        return fun(a,b);
    }
};


