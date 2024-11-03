class Solution {
public:
    bool rotateString(string s, string goal) {
        if ( goal.size() < s.size() ) return false;
        string temp;
        temp += goal;
        temp += goal;
        if ( temp.find(s) != string::npos){
            return true;
        }
        return false;
    }
};