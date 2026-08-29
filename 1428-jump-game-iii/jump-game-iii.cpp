class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        q.push(start);

        vector<int> vis(n,0);
        vis[start] = 1;

        while( !q.empty()){
            int tp = q.front();
            q.pop();

            if ( arr[tp] == 0 ) return true;

            if ( tp + arr[tp] < n && !vis[tp+arr[tp]]){
                vis[tp+arr[tp]] = 1;
                q.push(tp+arr[tp]);
            }

            if ( tp - arr[tp] >= 0 && !vis[tp-arr[tp]]){
                vis[tp-arr[tp]] = 1;
                q.push(tp-arr[tp]);
            }
        }
        return false;
    }
};