class Solution {
public:
    bool check(vector<vector<char>>& v,int x,int y){
        bool mp[10]={false};
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(v[i][j]!='.'){
                    if(mp[v[i][j]-'0']==true) return false;
                    mp[v[i][j]-'0']=true;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& v) {

        for(int i=0;i<9;i++){
            vector<bool> mp(10,false);
            for(int j=0;j<9;j++){
                if(v[i][j]!='.'){
                    if(mp[v[i][j]-'0']==true) return false;
                    mp[v[i][j]-'0']=true;
                }
            }
        }

        for(int i=0;i<9;i++){
            vector<bool> mp(10,false);
            for(int j=0;j<9;j++){
                if(v[j][i]!='.'){
                    if(mp[v[j][i]-'0']==true) return false;
                    mp[v[j][i]-'0']=true;
                }
            }
        }
    
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(check(v,i,j)==false) return false;
            }
        }
        return true;
    }
};
