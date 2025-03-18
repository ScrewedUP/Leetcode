class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitCount(32,0);
        int ans = 0;
        int l = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            for(int j = 31 ; j >= 0 ; j--){
                if ((curr&(1<<j)) != 0){
                    bitCount[j]++;
                }
            }
            for(int j = 0 ; j < 32 ; j++){
                if ( bitCount[j] > 1 ){
                    while(bitCount[j] > 1 ){
                        int newCurr = nums[l];
                        for(int k = 31 ; k >= 0 ; k--){
                            if ((newCurr&(1<<k)) != 0){
                                bitCount[k]--;
                            }
                        }
                        l++;
                    }
                }
            }
            ans = max(ans,i - l + 1);
        }
        return ans;
    }
};