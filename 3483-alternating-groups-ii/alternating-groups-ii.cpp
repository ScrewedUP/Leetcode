class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 0;
        int curr = 1;
        int n = colors.size();
        
        for(int i = 1 ; i < n + k - 1 ; i++){
        if ( colors[i%n] == 1 - colors[(i-1)%n]){
            curr++;
            if ( curr == k ){
                cnt++;
                curr--;
            }
        }
        else{
            curr = 1;
        }
        
        }
        
        return cnt;

    }
};