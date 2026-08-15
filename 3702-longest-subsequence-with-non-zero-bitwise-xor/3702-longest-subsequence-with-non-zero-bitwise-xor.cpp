class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zeroCnt = 0;
        int x = 0;
        for(auto i : nums){
            x^=i;
            if ( i == 0 ) zeroCnt++;
        }
        if ( x != 0 ) return nums.size();
        if ( x == 0 && zeroCnt == nums.size()) return 0;
        return nums.size() - 1;
    }
};