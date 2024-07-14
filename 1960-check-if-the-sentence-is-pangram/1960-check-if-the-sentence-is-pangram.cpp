class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int> m;
        bool isPangram = true;
        for(int i = 0; i < sentence.size() ; i++){
            m[sentence[i]]++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if ( m[97+i] == 0 ){
                isPangram = false;
                break;
            }
        }
        if ( isPangram ) return true;
        return false;
    }
};