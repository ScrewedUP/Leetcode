class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto x : nums){
            pq.push(x);
        }
        while(pq.top() < k){
            auto x1 = pq.top();
            pq.pop();
            auto x2 = pq.top();
            pq.pop();
            long long val = min(x1,x2)*2 + max(x1,x2);
            pq.push(val);
            cnt++;
        }
        return cnt;
    }
};