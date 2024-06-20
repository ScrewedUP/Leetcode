class Solution {
public:
    bool isPossible(int mid, int m , int n,vector<int> &position){
        int currBall = 1;
        int lastLoc = position[0];

        for(int i = 0 ; i < n ; i++){
            if ( position[i] - lastLoc >= mid){
                currBall++;
                if ( currBall == m ) return true;
                lastLoc = position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int maxi = *max_element(position.begin(),position.end());
        int low = 0;
        int high = maxi;
        int ans = -1;
        while ( low <= high ){
            int mid = ( low + high ) /2;
            if ( isPossible(mid,m,n,position)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};