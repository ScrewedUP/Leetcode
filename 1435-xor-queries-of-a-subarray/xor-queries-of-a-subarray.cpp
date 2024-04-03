class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> Xor(n);
        Xor[0] = arr[0];
        for(int i = 1 ; i < n ; i++){
            Xor[i] = Xor[i-1]^arr[i]; 
        }
        vector<int> ans;
        for(auto it : queries){
            int first = it[0];
            int last = it[1];
            if ( first == 0 ){
                ans.push_back(Xor[last]);
            }
            else ans.push_back(Xor[last]^Xor[first-1]);
        }
        return ans;
    }
};