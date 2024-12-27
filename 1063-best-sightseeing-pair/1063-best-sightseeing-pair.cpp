class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = INT_MIN;
        int maxLeft = values[0];

        for(int i = 1 ; i < n ; i++){
            ans = max(ans,maxLeft + values[i] - i);
            maxLeft = max(maxLeft,values[i] + i);
        }
        return ans;
    }
};