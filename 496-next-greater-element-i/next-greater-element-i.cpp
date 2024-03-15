class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        s.push(INT_MAX);
        map<int,int> m;
        int n = nums2.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            int curr = nums2[i];
            while ( s.top() < curr ){
                s.pop();
            }
            m[curr] = s.top();
            s.push(curr);
        }   
        vector<int> ans;
        for(auto it : nums1){
            int currAns = m[it];
            if ( m[it] == INT_MAX ) ans.push_back(-1);
            else ans.push_back(currAns);
        }
        return ans;
    }
};