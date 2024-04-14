class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        map<int,int> m;
        for(auto it : primes){
            m[it]++;
        }
        vector<int> indies;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( m.find(nums[i]) != m.end()){
                indies.push_back(i);
            }
        }
        return abs(indies.back() - indies[0]);
        
    }
};