class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto s : operations){
            if ( s.find('+') != std::string::npos){
                ans++;
            }
            else ans--;
        }
        return ans;
    }
};