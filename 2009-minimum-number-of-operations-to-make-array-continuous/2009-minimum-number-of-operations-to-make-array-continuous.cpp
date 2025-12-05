class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        set<int> s(begin(nums),end(nums));
        vector<int> temp(begin(s),end(s));

        for(int i = 0 ; i < temp.size() ; i++){
            int ele = temp[i];
            int L = ele;
            int R = L + n - 1;

            int j = upper_bound(begin(temp),end(temp),R) - begin(temp);
            int inrange = j - i;
            int outOfRange = n - inrange;

            ans = min(ans,outOfRange);
        }
        return ans;
    }
};