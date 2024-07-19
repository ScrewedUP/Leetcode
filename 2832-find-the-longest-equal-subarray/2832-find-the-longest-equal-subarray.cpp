class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }

        int maxi = 0;

        for (auto it : m) {
            int n = it.second.size();
            int j = k;
            int currMaxi = 1;
            int globalMaxi = 1;

            for (int i = 1; i < n; i++) {
                int gap = it.second[i] - it.second[i - 1] - 1;

                if (gap <= j) {
                    currMaxi++;
                    j -= gap;
                } else {
                    globalMaxi = max(globalMaxi, currMaxi);
                    while (j < gap && currMaxi > 0) {
                        currMaxi--;
                        j += it.second[i - currMaxi] - it.second[i - currMaxi - 1] - 1;
                    }
                    currMaxi++;
                    j -= gap;
                }
            }
            globalMaxi = max(globalMaxi, currMaxi);
            maxi = max(maxi, globalMaxi);
        }

        return maxi;
    }
};
