class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans;
        for(int i = 0 ; i < 100 ; i++){
            int a = pow(x,i);
            if ( a > bound ){
                break;
            }
            for(int j = 0 ; j < 100 ; j++){
                int b = pow(y,j);
                if ( b > bound ){
                    break;
                }
                int ans1 = a + b;
                if ( a + b > bound ){
                    break;
                }
                else{
                    ans.insert(ans1);
                }
            }
        }
        vector<int> temp;
        for(auto it : ans) temp.push_back(it);
        return temp;
    }
};