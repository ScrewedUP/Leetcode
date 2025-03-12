class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int e = 0;
        int o = 0;
        for(auto it : nums){ 
            if (it != 0) {
                if ( it <  0 ) e++;
                else o++;
            }
        }
        return max(e,o);
    }
};