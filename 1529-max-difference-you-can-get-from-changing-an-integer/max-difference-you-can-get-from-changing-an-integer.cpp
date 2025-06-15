class Solution {
public:
    int maxDiff(int num) {
        string s1 = to_string(num);
        string s2 = s1;
        char c = '9';
        for(int i = 0 ; i < s1.size() ; i++){
            if ( s1[i] != '9'){
                c = s1[i];
                break;
            }
        }
        for(int i = 0 ; i < s1.size() ; i++){
            if ( s1[i] == c){
                s1[i] = '9';
            }
        }
        cout << s1 << " ";
        char c2 = '1';
        if ( s2[0] != '1'){
            c2 = s2[0];
            for(int i = 0 ; i < s1.size() ; i++){
                if ( s2[i] == c2){
                    s2[i] = '1';
                }
            }
        }
        else{
            if ( s2.size() > 1){
                for(int i = 0 ; i < s2.size() ; i++){
                    if ( s2[i] != '1' && s2[i] != '0'){
                        c2 = s2[i];
                        break;
                    }
                }
                if ( c2 != '1'){
                    for(int i = 0 ; i < s2.size() ; i++){
                        if ( s2[i] == c2){
                            s2[i] = '0';
                        }
                    }
                }
                
            }
        }
        
        // cout << s1 << " " << s2;
        int x = stoi(s1);
        int y = stoi(s2);
        return x - y;
    }
};