class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n,0);

        stack<pair<int,int>> st;

        for(int i = n - 1 ; i >= 0 ; i--){
            int cnt = 0;
            while( !st.empty() && t[i] >= st.top().first){
                cnt++;
                st.pop();
            }
            if ( !st.empty()){
                ans[i] = st.top().second - i;
            }
            st.push({t[i],i});
        }

        return ans;
    }
};