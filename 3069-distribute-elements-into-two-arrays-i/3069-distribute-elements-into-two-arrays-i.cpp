class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> left,right;

        left.push_back(nums[0]);
        right.push_back(nums[1]);

        for(int i = 2 ; i < nums.size() ; i++){
            if ( left.back() > right.back()) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        for(auto i : right) left.push_back(i);
        return left;
    }
};