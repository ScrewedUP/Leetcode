class Solution {
public:
    /*
        in n^2 i need to check the longest palindrome

        checking every substring take n^2 time , 

    */

    bool p(string &s){
        int i = 0 , j = s.size() - 1;
        while ( i < j ){
            if ( s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int sz = 0;
        string ans;
        for(int i = 0 ; i < s.size() ; i++){
            string temp;
            for(int j = i ; j < s.size() ; j++){
                temp += s[j];
                if ( p(temp)){
                    if ( temp.size() > sz ){
                        sz = temp.size();
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};