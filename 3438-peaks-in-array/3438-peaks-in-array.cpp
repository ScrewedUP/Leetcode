class SegmentTree {
    private:
        vector<int> seg;
        vector<int> arr;
        int size;

        int checkPeak(int i) {
            if(i <= 0 || i >= this->size - 1) return 0;
            return arr[i - 1] < arr[i] && arr[i] > arr[i + 1] ? 1 : 0;
        }
        
        int queryHelper(int ind, int low, int high, int l, int h) {
            if(l > high || h < low) {
                return 0;
            }
            if(l <= low && h >= high) return seg[ind];
            int mid = low + (high - low) / 2;
            int left = queryHelper(2*ind + 1, low, mid, l, h);
            int right = queryHelper(2*ind + 2, mid + 1, high, l, h);
            return left + right;
        }

        void updatePeak(int ind, int low, int high, int idx) {
            if(low == high && low == idx) {
                seg[ind] = checkPeak(idx) ? 1 : 0;
                return;
            }
            int mid = low + (high - low) / 2;
            if(idx <= mid) updatePeak(2*ind + 1, low, mid, idx);
            else updatePeak(2*ind + 2, mid + 1, high, idx);
            seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
        }
        void updateHelper(int ind, int low, int high, int idx, int val) {
            int mid = low + (high - low) / 2;
            if(low == high && low == idx) {
                arr[low] = val;
                seg[ind] = checkPeak(low) ? 1 : 0;
            } else {
                if(idx <= mid) {
                    updateHelper(2*ind + 1, low, mid, idx, val);
                } else {
                    updateHelper(2*ind + 2, mid + 1, high, idx, val);
                }
                seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
            }
        }
        
        void Build(int ind, int low, int high) {
            if(low == high) {
                seg[ind] = checkPeak(low) ? 1 : 0;
                return;
            }
            int mid = low + (high - low) / 2;
            Build(2*ind + 1, low, mid);
            Build(2*ind + 2, mid + 1, high);
            seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
        }
    public:
        SegmentTree(vector<int> & arr) {
            int n = arr.size();
            this -> size = n;
            this -> arr = arr;
            this -> seg.resize(4*n);
            this -> Build(0, 0, n - 1);
        }
        int Query(int low, int high) {
            return queryHelper(0, 0, size - 1, low + 1, high - 1);
        }
        void Update(int idx, int val) {
            updateHelper(0, 0, size - 1, idx, val);
            if(idx > 0) updateHelper(0, 0, size - 1, idx - 1, arr[idx-1]);
            if(idx < size - 1) updateHelper(0, 0, size - 1, idx + 1, arr[idx+1]);
        }
        void Print() {
            for(int & ele : seg) cout << ele <<" ";
            cout << endl;
        }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int> & nums, vector<vector<int>> & queries) {
        SegmentTree * sgt = new SegmentTree(nums);
        // sgt->Print();
        vector<int> ans;
        for(auto & q : queries) {
            int type = q[0];
            if(type == 1) {
                int l = q[1];
                int r = q[2];
                int res = sgt->Query(l, r);
                ans.push_back(res);
            } else if(type == 2) {
                int idx = q[1];
                int val = q[2];
                sgt->Update(idx, val);
                // sgt->Print();
            }
        }
        return ans;
    }
};
