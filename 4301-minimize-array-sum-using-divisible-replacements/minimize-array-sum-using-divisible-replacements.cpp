const int N = 100001;

vector<vector<int>> d(N);

bool init = [](){
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            d[j].push_back(i);
        }
    }
    return true;
}();

class Solution {
public:
    /*
        [6,3,2]
    */
    long long minArraySum(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it : nums) m[it]++;
        sort(nums.rbegin(),nums.rend());
        for(int i = 0 ; i < nums.size() ; i++){
            int x = nums[i];
            for(auto j : d[x]){
                if ( m.find(j) != m.end()){
                    nums[i] = j;
                    break;
                }
            }
        }
        long long sum = 0;
        for(auto it : nums) sum += it;
        return sum;
    }

};