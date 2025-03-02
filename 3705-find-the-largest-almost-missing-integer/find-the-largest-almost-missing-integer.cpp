class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> m;
        for(int i = 0 ; i < nums.size() ; i++){
            set<int> s;
            if ( i + k <= n){
                for(int j = i ; j < i+k ; j++){
                    s.insert(nums[j]);
                }    
            }
            for(auto it : s){
                m[it]++;
            }
        }
        
        int maxi = -1;
        for(auto it : m){
            if ( it.second == 1){
                maxi = max(maxi,it.first);
            }
        }
        return maxi;
    }
};