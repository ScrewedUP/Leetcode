class Solution {
public:
    /*
        answer here is least weight of binary search will be on 
        weight 
    */
    bool check(int mx,vector<int> &nums,int k){
        int cnt = 0;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( sum + nums[i] > mx ){
                sum = nums[i];
                cnt++;
            }
            else sum += nums[i];
        }

        return cnt < k;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while( l <= h ){
            int mid = (l+h)/2;
            if ( check(mid,weights,days)){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};