class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }

        sort(v.rbegin(),v.rend());

        stack<double> st;
        for(auto x:v){
            auto pos = x.first;
            auto spd = x.second;
            double t = (double)(target-pos)/spd;
            if(!st.empty()){
                if(st.top()<t){
                    st.push(t);
                }
            }else st.push(t);
        }
        return st.size();
    }
};
