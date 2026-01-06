class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        for(int i = 1 ; i < n ; i++){
            int cnt = 1;
            char c = curr[0];
            string temp;
            if ( curr.size() == 1){
                temp = "11";
            }
            else{
                for(int j = 1 ; j < curr.size() ; j++){
                    if ( curr[j] == c ){
                        cnt++;
                        
                    }
                    else{
                        temp += ( cnt + '0');
                        temp += c;
                        cnt = 1;
                        c = curr[j];
                    }
                    if ( j == curr.size() - 1){
                            temp += ( cnt + '0');
                            temp += c;
                        }
                }
            }
            curr = temp;
        }
        return curr;
    }
};