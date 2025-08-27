class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if ( n % k != 0 ) return false;
        map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        int x = n/k;
        for(auto it : m){
            if ( it.second > x ) return false;
        }
        return true;
    }
};