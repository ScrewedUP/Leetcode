class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> m;
        for(auto it : nums) m[it]++;
        int x = original;
        while(true){
            if ( m.find(x) != m.end()){
                x *= 2;
            }
            else break;
        }
        return x;
    }
};