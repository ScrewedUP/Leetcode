class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> l,u;

        for(int i = 0 ; i < word.size() ; i++){
            if ( word[i] >= 'a' && word[i] <= 'z'){
                l[word[i]] = i;
            }
            else{
                if ( u.find(word[i]) == u.end()) u[word[i]] = i;
            }
        }
        int cnt = 0;
        for(auto it : l){
            char c = toupper(it.first);
            if ( u.find(c) != u.end()){
                if ( it.second < u[c]) cnt++;
            }
        }
        return cnt;
    }
};