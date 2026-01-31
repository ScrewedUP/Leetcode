class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> v;
        for(auto it : nums){
            if ( it >= 0 ) v.push_back(it);
        }
        if ( v.size() > 0 ) rotate(v.begin(),v.begin() + (k%v.size()) , v.end());
        int j = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( nums[i] >= 0 ){
                nums[i] = v[j];
                j++;
            }
        }
        return nums;
    }
};