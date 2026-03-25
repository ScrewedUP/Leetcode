class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int x = accumulate(nums.begin(),nums.end(),0);

        int y = 0;
        for(auto it : nums){
            if ( it < 10 ) y += it;
        }

        if ( 2*y == x ) return false;
        return true;
    }
};