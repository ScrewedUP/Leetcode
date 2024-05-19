class Solution {
public:
    unordered_map<string,int> m;
    int solve(int i , int k ,int j , int flag){
        if ( i > k + 1 || i < 0 ) return 0;
        int cnt = 0;
        if ( i == k ){
            cnt = 1;
        }
        string key = to_string(i) + to_string(j) + to_string(flag);
        if ( m.find(key) != m.end()){
            return m[key];
        }
        int one = 0;
        if ( i > 0 && flag == 1){
            one = solve(i-1,k,j,0);
        }
        int two = solve(i + (1 << j),k,j+1,1);

        return m[key] = cnt + one + two;
    }
    int waysToReachStair(int k) {
        return solve(1,k,0,1);
    }
};