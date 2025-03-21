class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // Fliping the ith bit of the i-th string will
        // guarantee a different string from all the
        // elements in the array 
        // ans will differ from every string in at least one position
        // Cantor's diagonal argumenti
        string ans;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( nums[i][i] == '0'){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }
        return ans;
    }
};