class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto it : nums){
            pq.push(it);
        }
        long long cnt = 0;
        while(pq.top() < k){
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            long long newNum = 2*num1;
            newNum += num2;
            cnt++;
            pq.push(newNum);
        }
        return cnt;
        
    }
};