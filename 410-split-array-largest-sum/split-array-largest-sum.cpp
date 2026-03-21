class Solution {
public:
    /*
        minimize the maximum -> BS on answer

        given nums , have to split that in the k subarrays
        such that the maximum sum across all k subarray is minimized

        BS on asnwer , here the answer is sum
    */

    bool check(int sum,vector<int> &nums,int k){
        cout << sum << " ";
        int cnt = 0;
        int runningSum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( runningSum + nums[i] > sum ){
                cnt++;
                runningSum = nums[i];
            }
            else runningSum += nums[i];
        }

        return cnt < k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0) + 1;
        int ans = 0;
        while ( low <= high ){
            int mid = (low+high)/2;

            // how this mid i need to check that wheather
            // i can split this array in k subarrays such that 
            // sum of each subarray is less than or equal to mid
            // if yes that can be a possible ans

            if ( check(mid,nums,k)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};