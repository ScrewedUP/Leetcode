class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        map<string,int> m;
        for(auto i : nums) m[i]++;

        for(auto it : nums){
            string curr = it;

            for(int i = 0 ; i < curr.size() ; i++){
                char c = curr[i];

                if ( c == '0'){
                    curr[i] = '1';
                }
                else curr[i] = '0';

                if ( m.find(curr) == m.end()) return curr;

                curr[i] = c;
            }
        }
        return "";
    }
};