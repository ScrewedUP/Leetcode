class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxi = 0;
        int left = 0;
        int sum = 0;
        for(int right = 0; right < s.size() ; right++){
            if ( s[right] != t[right]){
                sum += abs(s[right] - t[right]);
            }
            while ( sum > maxCost){
                sum -= abs(s[left] - t[left]);
                left++;
            }
            maxi = max(maxi,right - left + 1);
        }
        return maxi;
        // if ( maxi != 0 ) return maxi;
        // int p = 0;
        // int cnt = 0;
        // while ( s[p] == t[p] && p < s.size()){
        //     cnt++;
        //     p++;
        // }
        // return cnt;
    }
};