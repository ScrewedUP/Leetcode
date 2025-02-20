class Solution {
public:
    string ans;
    void solve(string s,int n,set<string> &st){
        if ( s.size() == n){
            if ( st.find(s) == st.end()){
                ans = s;
            }
            return;
        }
        solve(s+'0',n,st);
        solve(s+'1',n,st);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s(nums.begin(),nums.end());
        solve("",nums[0].size(),s);
        return ans;
    }
};