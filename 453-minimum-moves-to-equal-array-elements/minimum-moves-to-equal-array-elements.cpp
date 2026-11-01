class Solution {
public:
    /*
        2 4 6 8

        3 5 7 8

        4 6 8 8

        5 7 9 8

        6 8 9 9

        7 9 9 10

        8 10 10 10

        9 11 11 10

        10 12 11 11

        11 12 12 12

        12 13 13 12

        13 14 14 13 

        14 15 14 14

        15 15 15 15       
    */

    int minMoves(vector<int>& nums) {
        int offset = 0;
        sort(nums.begin(),nums.end());

        int x = 1;
        int ele = nums[0];
        int ans = 0;
        while ( x < nums.size()){
            int diff = nums[x] - ele + offset;

            ans += diff;

            offset += nums[x] - ele;
            ele = nums[x];

            

            x++;

        }

        return ans;
    }
};