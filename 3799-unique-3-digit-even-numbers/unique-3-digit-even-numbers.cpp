class Solution {
public:
    int totalNumbers(vector<int>& d) {
        set<int> s;
        int n = d.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < n ; k++){
                    if ( i != j && j != k && k != i){
                        int num = d[i]*100 + d[j]*10 + d[k];

                        if ( s.find(num) == s.end() && num % 2 == 0 && num >= 100 && num <= 999){
                            s.insert(num);
                        }
                    }
                }
            }
        }
        return s.size();
    }
};