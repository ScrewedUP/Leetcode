#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; 

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        ordered_multiset arr1Set, arr2Set;
        vector<int> result;
        arr1.push_back(nums[0]);
        arr1Set.insert(nums[0]);
        arr2.push_back(nums[1]);
        arr2Set.insert(nums[1]);

        for (int i = 2; i < n; i++) {
            int greaterInArr1 = arr1Set.size() - arr1Set.order_of_key(nums[i]+1);
            int greaterInArr2 = arr2Set.size() - arr2Set.order_of_key(nums[i]+1);

            // cout << greaterInArr1 << " " << greaterInArr2 << endl;
            if (greaterInArr1 > greaterInArr2) {
                arr1.push_back(nums[i]);
                arr1Set.insert(nums[i]);
            } 
            else if (greaterInArr1 < greaterInArr2) {
                arr2.push_back(nums[i]);
                arr2Set.insert(nums[i]);
            } 
            else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    arr1Set.insert(nums[i]);
                } 
                else {
                    arr2.push_back(nums[i]);
                    arr2Set.insert(nums[i]);
                }
            }
        }

        for (auto it: arr1) result.push_back(it);
        for (auto it : arr2) result.push_back(it);

        return result;
    }
};
