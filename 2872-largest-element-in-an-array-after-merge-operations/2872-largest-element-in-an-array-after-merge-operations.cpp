class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        stack<long long> st;
        st.push(nums.back());
        for(int i = nums.size() - 2 ; i >= 0 ; i--){
            long long curr = nums[i];
            bool ok = false;
            while ( !st.empty() && st.top() >= curr ){
                long long x = st.top();
                st.pop();
                curr += x;
                
                ok = true;
            }
            st.push(curr);
        }

        vector<long long> ans;
        while( !st.empty()){
            long long x = st.top();
            st.pop();
            ans.push_back(x);
        }
        long long maxi = *max_element(ans.begin(),ans.end());
        return maxi;

    }
};