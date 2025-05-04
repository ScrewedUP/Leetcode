class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num(100);
        int ret = 0;
        for (auto& it : dominoes) {
            int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
            /*
                12 -> val = 12
                21 -> val = 12
                [[1,2],[1,2],[1,1],[1,2],[2,2]]

                num[12]++;
                num[12]++;
                num[11]++;
                num[12]++;
                num[22]++;
            */

            ret += num[val];
            num[val]++;
        }
        return ret;
    }
};