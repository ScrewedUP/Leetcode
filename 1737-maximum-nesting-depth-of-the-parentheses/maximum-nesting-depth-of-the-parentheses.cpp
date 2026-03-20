class Solution {
public:
    int maxDepth(string s) {
        int d = 0;
        int mx = INT_MIN;
        for(auto c : s){
            if ( c == '('){
                d++;
            }
            else if ( c == ')') d--;
            mx = max(mx,d);
        }
        return mx;

    }
};