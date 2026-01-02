class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> m;
        priority_queue<int> pq;
        int l = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            m[nums[i]]++;
            pq.push(nums[i]);
            if ( i - l + 1 == k){
                while(pq.size() > 0 && m[pq.top()] == 0){
                    pq.pop();
                }
                ans.push_back(pq.top());
                m[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};