class Solution {
public:
    int minInsertions(string s) {
        /*
            if i find
                )) without a opening ( -> I need one (
                ) wih a opening ( -> I need one )
                ) without a opening ( -> I need two ()
        */

        int openingCount = 0;
        int n = s.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if ( s[i] == '(') openingCount++;
            else if ( s[i] == ')'){
                if ( i + 1 < n ){
                    if ( openingCount > 0){
                        if ( s[i+1] == ')'){
                            openingCount--;
                            i++;
                        }
                        else{
                            openingCount--;
                            ans++;
                        }
                    }
                    else{
                        if ( s[i+1] == ')'){
                            i++;
                            ans++;
                        }
                        else{
                            ans+=2;
                        }
                    }
                    
                }
                else{
                    if ( openingCount > 0 ){
                        ans++;
                        openingCount--;
                    }
                    else ans += 2;
                }
            }
        }
        if ( openingCount > 0 ){
            ans += 2*openingCount;
        }
        return ans;
    }
};