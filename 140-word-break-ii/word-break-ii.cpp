class Solution {
public:
    vector<string> ans;
     void solve(int idx, int start, vector<string> temp,string &s, map<string, int> &m, vector<vector<int>> &memo) {
        if (idx == s.size()) {
            string thisOne = s.substr(start, idx - start); 
            if ( m.find(thisOne) != m.end() ){
                temp.push_back(thisOne);
                string curr;
                for(int i = 0 ;i < temp.size() ; i++){
                    if ( i != temp.size() - 1){
                        curr += temp[i];
                        curr += ' ';
                    }
                    else{
                        curr += temp[i];
                    }
                }
                ans.push_back(curr);
                return;
            }
            return;
        }
        string temp1 = s.substr(start, idx - start + 1);
        if (m.find(temp1) != m.end()) {
            temp.push_back(temp1);
            solve(idx + 1, idx + 1, temp,s, m, memo);
            temp.pop_back();
        }
        
        solve(idx + 1, start, temp,s, m, memo);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, int> m;
        for (auto &word : wordDict) {
            m[word]++;
        }
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        vector<string> temp;
        solve(0, 0, temp,s, m, memo);
        return ans;
    }
};