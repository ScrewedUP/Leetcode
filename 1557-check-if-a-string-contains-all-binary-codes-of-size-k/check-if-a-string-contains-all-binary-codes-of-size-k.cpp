class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int l = 0;
        int n = s.size();
        string temp;
        for(int i = 0 ; i < n ; i++){
            temp += s[i];
            if ( i - l + 1 == k){
                st.insert(temp);
                l++;
                string temp2;
                for(int j = 1 ; j < temp.size() ; j++){
                    temp2 += temp[j];
                }
                temp = temp2;
            }
        }
        int x = pow(2,k);
        if ( st.size() == x ) return true;
        return false;
    }
};