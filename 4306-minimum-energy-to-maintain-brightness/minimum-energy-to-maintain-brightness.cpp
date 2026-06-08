class Solution {
public:
    int ceil(int x,int y){
        if ( x % y == 0 ) return x/y;
        else return x/y + 1;
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> over;
        over.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i++){
            auto prev = over.back();
            auto curr = intervals[i];

            if ( prev[1] >= curr[0] && prev[1] >= curr[1]){
                auto nw = prev;
                over.pop_back();
                over.push_back(nw);
            }
            else if ( prev[1] >= curr[0]){
                auto nw = {prev[0],curr[1]};
                over.pop_back();
                over.push_back(nw);
            }
            else{
                over.push_back(curr);
            }
        }
        long long ans = 0;
        // for(auto it : over) cout << it[0] << " " << it[1] << endl;
        for(auto it : over){
            int st = it[0];
            int end = it[1];

            long long time = end - st + 1;

            //enery consumed = time * number of bulbs


            // _ 1 _ _ 1 _ _ 1 _ _ 1

            // 1 bulb 3
            // total = min(n,number of bulbs open * 3)

            long long num = ceil(brightness,3);

            ans += num*time;
        }
        return ans;
    }
};