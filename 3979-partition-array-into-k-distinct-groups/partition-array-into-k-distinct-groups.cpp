class Solution {
public:
    /*
        k == 2;
        1,1,2,2,3,3
        [1_ 2_] [1_ 3_] [2_ 3_] 
    */
    bool partitionArray(vector<int>& nums, int k) {
        if ( nums.size() % k != 0 ) return false;
        int n = nums.size();
        int x = n/k;
        unordered_map<int,int> m;
        for(auto it : nums) m[it]++;
        for(auto it : m){
            if ( it.second > x ) return false;
        }
        return true;
    }
};