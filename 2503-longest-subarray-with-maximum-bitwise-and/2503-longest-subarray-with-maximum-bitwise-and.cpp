class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int maxCnt = 0;
        bool ok = false;
        for(int i = 0 ; i < nums.size() ; i++){
            if (nums[i] == maxi ){
                if ( !ok ){
                    cnt++;
                    ok = true;
                }
                else if ( ok ) cnt++;

            }
            else{
                ok = false;
                maxCnt = max(maxCnt,cnt);
                cnt = 0;
            }
        }
        maxCnt = max(maxCnt,cnt);
        return maxCnt;
    }
};