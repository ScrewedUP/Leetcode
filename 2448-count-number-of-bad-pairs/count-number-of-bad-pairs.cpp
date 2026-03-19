class Solution {
public:
    /*
        a bad pair (i,j) is i < j and 
        j - i != nums[j] - nums[i]

        nums[i] - i != nums[j] - j

        4 1 3 3

        4 0 1 0

    */
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        map<int,int> m;
        vector<int> t(n);
        for(int i = 0 ; i < n ; i++){
            t[i] = nums[i] - i;
        }
        for(int i = 0 ; i < n ; i++){
            ans += i - m[t[i]];
            m[t[i]]++;
        }
        return ans;
    }
};