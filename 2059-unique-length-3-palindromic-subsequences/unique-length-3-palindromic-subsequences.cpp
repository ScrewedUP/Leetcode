class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // store the first and last occurance of the char
        // the number of elements in between the first and last
        // is the number of palindromes that character will contribute 
        // to the answer

        vector<int> firstOccurance(26,-1);
        vector<int> lastOccurance(26,-1);

        for(int i = 0 ; i < s.size() ; i++){
            if ( firstOccurance[s[i] - 'a'] == -1){
                firstOccurance[s[i] - 'a'] = i;
            }
            lastOccurance[s[i] - 'a'] = i;
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            if ( firstOccurance[i] != -1){
                set<int> st;
                for(int j = firstOccurance[i] + 1 ; j < lastOccurance[i] ; j++){
                    st.insert(s[j]);
                }
                ans += st.size();
            }
        }
        return ans;
    }
};