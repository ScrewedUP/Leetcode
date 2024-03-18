class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int> &a1 , vector<int> &b1){
            if ( a1[1] == b1[1] ) return a1[0] < b1[0];
            return a1[1] < b1[1]; 
        });
        //[1,6] [2,8] [7,12] [10,16]
        int cnt = 1;
        int p = points[0][1];
        for(int i = 1 ; i < points.size() ; i++){
            while ( i < points.size() && points[i][0] <= p ){
                i++;
            }
            
            if ( i < points.size() ){
                p = points[i][1];
                cnt++;
            }
            
        }
        return cnt;
    }
};