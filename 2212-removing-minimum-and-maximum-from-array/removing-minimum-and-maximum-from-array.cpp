class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        /*

            either all left, either all right,left and right
        */

        int idxM = max_element(nums.begin(),nums.end()) - nums.begin();
        int idxS = min_element(nums.begin(),nums.end()) - nums.begin();

        int n = nums.size();

        int ans = max(idxM,idxS) + 1;

        int right = n - min(idxM,idxS);

        ans = min(ans,right);

        int leftR = min(idxM,idxS) + 1;
        int rightR = n - max(idxM,idxS);

        ans = min(ans,leftR+rightR);
        return ans;
    }
};