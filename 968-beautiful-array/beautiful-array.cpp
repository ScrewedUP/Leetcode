class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);
        if( n == 1 ) return ans; 
        
        while( ans.size() < n){
            vector<int> temp;
            for(auto i : ans ){
                if( 2*i <= n){
                    temp.push_back(2*i);
                }
            }
            for(auto i : ans){
                if(2*i -1 <= n){
                    temp.push_back(2*i-1);
                }
            }
            ans = temp;
        }
        return ans;
    }
};