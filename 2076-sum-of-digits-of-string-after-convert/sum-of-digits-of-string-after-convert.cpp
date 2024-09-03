class Solution {
public:
    int solve(int n){
        int sum = 0;

        while ( n){
            sum += n % 10;
            n/=10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int num = 0;
        for(auto it : s){
            int x = solve(it - 'a' + 1);
            num += x;
        }
        for(int i = 0 ; i < k -1  ; i++){
            num = solve(num);
        }
        return num;
    }
};