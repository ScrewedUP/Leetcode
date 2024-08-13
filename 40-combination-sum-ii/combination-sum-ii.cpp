class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(c.begin(), c.end());
        solve(0, c, temp, t, ans);
        return ans;
    }

    void solve(int idx, vector<int>& c, vector<int>& temp, int t, vector<vector<int>>& ans) {
        if (t == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < c.size(); ++i) {
            if (i > idx && c[i] == c[i - 1]) continue; 
            if (c[i] > t) break;
            temp.push_back(c[i]);
            solve(i + 1, c, temp, t - c[i], ans);
            temp.pop_back();
        }
    }
};
