class Solution {
public:
    bool rotateString(string s, string goal) {
        if ( goal.size() < s.size() ) return false;
        string temp;
        temp += goal;
        temp += goal;
        if ( temp.contains(s)){
            return true;
        }
        return false;
    }
};