class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        vector<int> v;
        for(int i = 0 ; i < words.size() ; i++){
            if ( words[i] == target){
                v.push_back(i);
            }
        }

        if ( v.size() == 0 ) return -1;

        /*
            if found there are 2 ways to reach target

            go circular towards left and go circular towards right
        */

        // cases
        int n = words.size();
        int ans = INT_MAX;
        for(auto idx : v){
            if ( idx < startIndex ){
            // find the circular distance for right
            // or simple distance from left
                int leftDistance = startIndex - idx;
                int rightDistance = n - startIndex + idx;
                ans = min(ans,min(leftDistance,rightDistance));
            }
            else{
                int rightDistance = idx - startIndex;
                int leftDistance = startIndex + n - idx;

                ans = min(ans,min(leftDistance,rightDistance));
            }
        }
        

        return ans;
    }
};