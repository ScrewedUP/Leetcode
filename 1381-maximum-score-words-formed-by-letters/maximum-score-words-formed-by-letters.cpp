class Solution {
public:
    int solve(int idx,vector<string>& words,map<char,int> m,vector<int> &score){
        if ( idx >= words.size() ) return 0;
        int take = 0;
        int notTake = 0;
        bool ok = true;
        vector<int> req(26,0);
        for(auto it : words[idx]){
            req[it - 'a']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if ( req[i] > 0 ){
                char c = i + 'a';
                if ( m[c] < req[i] ){
                    ok = false;
                    break;
                }
            }
        }
        map<char,int> mt = m;
        if ( ok ){
            int myScore = 0;
            for(auto it : words[idx]){
                int ch = it - 'a';
                myScore += score[ch];
                m[it]--;
            }
            take = myScore + solve(idx+1,words,m,score);
        }
        notTake = solve(idx+1,words,mt,score);
        return max(take,notTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int> m;
        for(auto it : letters) m[it]++;
        return solve(0,words,m,score);
    }
};