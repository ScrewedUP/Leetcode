class Solution {
public:
    vector<int> GetNextSmaller(vector<int>& h , int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = n - 1 ; i >= 0 ; i--){
            int curr = h[i];
            while ( st.top() != -1 && h[st.top()] >= curr ){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> GetPrevSmaller(vector<int>& h , int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            int curr = h[i];
            while ( st.top() != -1 && h[st.top()] >= curr ){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = GetNextSmaller(heights,n);
        
        vector<int> prev = GetPrevSmaller(heights,n);
        // for(auto it : prev ){
        //     cout << it << " ";
        // }
        int area = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int currHeight = heights[i];
            if ( next[i] == -1 ){
                next[i] = n;
            }
            int currWidth = next[i] - prev[i] - 1;
            int currArea = currHeight * currWidth;
            area = max(area,currArea); 
        }
        return area;
    }
};