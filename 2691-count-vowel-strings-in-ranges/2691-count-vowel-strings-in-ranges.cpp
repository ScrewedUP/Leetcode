class Solution {
public:
    bool isVowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }
    int check(string &s){
        return isVowel(s[0]) && isVowel(s[s.size()-1]);
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        vector<int> pre(words.size());
        pre[0] = check(words[0]);
        for(int i = 1 ; i < words.size() ; i++){
            pre[i] = pre[i-1] + check(words[i]);
        }
        vector<int> ans;
        for(int i = 0 ; i < q.size() ; i++){
            ans.push_back(pre[q[i][1]] - (q[i][0]>0?pre[q[i][0]-1] : 0));
        }
        return ans;
    }
};