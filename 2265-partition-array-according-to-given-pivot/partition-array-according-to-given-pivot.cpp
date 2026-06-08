class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left,right,middle;

        for(int i = 0 ;i < nums.size() ; i++){
            if ( nums[i] < pivot) left.push_back(nums[i]);
            else if ( nums[i] > pivot ) right.push_back(nums[i]);
            else middle.push_back(nums[i]);
        }

        vector<int> ans;
        for(auto it : left) ans.push_back(it);
        for(auto it : middle) ans.push_back(it);
        for(auto it : right) ans.push_back(it);
        return ans;
    }

};