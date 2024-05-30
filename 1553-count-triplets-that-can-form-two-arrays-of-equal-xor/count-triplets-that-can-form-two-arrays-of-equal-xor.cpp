class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> xoor(n);
        xoor[0] = arr[0];
        for(int i = 1 ; i < n ; i++){
            xoor[i] = xoor[i-1]^arr[i];
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                for(int k = j ; k < n ; k++){
                    if ( i == 0 ){
                        if ( xoor[j-1] == (xoor[k]^xoor[j-1])) cnt++;
                    }
                    else{
                        if ( xoor[j-1]^xoor[i-1] == xoor[k]^xoor[j-1]) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};