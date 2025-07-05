class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> m;
        for(auto it : arr){
            m[it]++;
        }
        int maxi = -1;
        for(auto it : m){
            if ( it.first == it.second){
                maxi = max(maxi,it.first);
            }
        }
        return maxi;
    }
};