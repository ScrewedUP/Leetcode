class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int f = 0;
        int t = 0;
        int tw = 0;
        bool ok = true;
        for(int i = 0 ; i < b.size() ; i++){
            if ( b[i] == 5 ){
                f++;
            }
            else if ( b[i] == 10){
                if ( f > 0 ){
                    f--;
                    t++;
                }
                else{
                    ok = false;
                    break;
                }
            }
            else{
                if ( t > 0 && f > 0){
                    t--;
                    f--;
                    tw++;
                }
                else if ( f > 2 ){
                    f -= 3;
                    tw++;
                }
                else{
                    ok = false;
                    break;
                }
            }
        }
        return ok;
    }
};