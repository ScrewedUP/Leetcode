class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int,int> m;
        int x = 0;
        int y = nums.size() - 1;
        while ( x < y ){
            m[abs(nums[x]-nums[y])]++;
            x++;y--;
        }
        int maxi = -1;
        int diff = -1;
        int secondMaxi = -1;
        int secondDiff = -1;

        for (auto it : m) {
            if (it.second > maxi) {
                secondMaxi = maxi;
                secondDiff = diff;
                maxi = it.second;
                diff = it.first;
            } else if (it.second > secondMaxi) {
                secondMaxi = it.second;
                secondDiff = it.first;
            }
        }
        // cout << maxi << " ";
        if ( maxi == -1 ) return 0;
        int i = 0 , j = nums.size() - 1;
        int cnt = 0;
        int cnt2 = 0;
        while ( i < j ){
            int currDiff = abs(nums[i] - nums[j]);
            if ( currDiff == diff ){
                i++;j--;
                continue;
            }
            else{
                int left = nums[i];
                int right = nums[j];
                if ( currDiff > diff ){
                    // cout << i << "|1|" << endl;
                    cnt++;
                    i++;j--;
                }
                else{
                    // cout << i;
                    int req = diff - currDiff;
                    if ( abs(right) >= diff || abs(left) >= diff || abs(k - left) >= diff || abs(k-right) >= diff ){
                        cnt++;
                        // cout << i << "|2|" << endl;
                        i++;j--;
                    }
                    else{
                        cnt += 2;
                        // cout << i << "|3|" << endl;
                        i++;j--;
                    }
                }
            }
        }
        i = 0 ; j = nums.size() - 1;
        while ( i < j ){
            int currDiff = abs(nums[i] - nums[j]);
            if ( currDiff == secondDiff ){
                i++;j--;
                continue;
            }
            else{
                int left = nums[i];
                int right = nums[j];
                if ( currDiff > secondDiff ){
                    // cout << i << "|1|" << endl;
                    cnt2++;
                    i++;j--;
                }
                else{
                    // cout << i;
                    int req = secondDiff - currDiff;
                    if ( abs(right) >= secondDiff || abs(left) >= secondDiff || abs(k - left) >= secondDiff || abs(k-right) >= secondDiff ){
                        cnt2++;
                        // cout << i << "|2|" << endl;
                        i++;j--;
                    }
                    else{
                        cnt2 += 2;
                        // cout << i << "|3|" << endl;
                        i++;j--;
                    }
                }
            }
        }
        return min(cnt,cnt2);
    }
};
