class Solution {
public:
    int distMoney(int money, int children) {
        if ( money < children ) return -1;
        money -= children;
        int cnt = 0;
        for(int i = 0 ; i < children ; i++){
            if ( money <= 0 ) break;
            if ( i == children - 1 && money > 0){
                if ( money == 7 ){
                    cnt++;
                    break;
                }
                else{
                    break;
                }
            }
            if ( money >= 7 ){
                int rem = money - 7;
                if ( rem == 3 && i == children - 2){
                    break;
                }
                else{
                    money -= 7;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};