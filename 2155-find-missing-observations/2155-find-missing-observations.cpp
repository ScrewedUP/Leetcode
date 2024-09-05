class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(auto it : rolls) sum += it;
        int remSum = mean*(m+n) - sum;
        vector<int> v(n,1);
        remSum -= n;
        if ( remSum < 0 ) return {};
        for(int i = 0 ; i < n ; i++){
            if ( remSum > 5 ){
                v[i] = 6;
                remSum -= 5;
            }
            else{
                v[i] += remSum;
                break;
            }
        }
        int sum2 = 0;
        for(int i = 0 ; i < m ; i++){
            sum2 += rolls[i];
        }
        for(int i = 0 ; i < n ; i++){
            sum2 += v[i];
        }
        if ( (sum2 / (m+n)) != mean  ) return {};
        return v;
    }
};