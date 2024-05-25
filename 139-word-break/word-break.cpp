class Solution {
public:
    bool solve(int idx, int start, string &s, map<string, int> &m, vector<vector<int>> &memo) {
        if (idx == s.size()) {
            return m.find(s.substr(start, idx - start)) != m.end();
        }
        
        if (memo[idx][start] != -1) return memo[idx][start];
        
        string temp = s.substr(start, idx - start + 1);
        
        bool take = false;
        if (m.find(temp) != m.end()) {
            take = solve(idx + 1, idx + 1, s, m, memo);
        }
        
        bool notTake = solve(idx + 1, start, s, m, memo);
        
        return memo[idx][start] = take | notTake;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> m;
        for (auto &word : wordDict) {
            m[word]++;
        }
        
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        return solve(0, 0, s, m, memo);
    }
};
