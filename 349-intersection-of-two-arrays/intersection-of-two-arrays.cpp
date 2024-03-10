class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n = nums1.size() , m = nums2.size();
        int i = 0 , j = 0;
        vector<int> interSectionArray;
        while( i < n && j < m ){
            if ( nums1[i] < nums2[j] ) i++;
            else if ( nums1[i] > nums2[j] ) j++;
            else {
                if ( interSectionArray.size() == 0 ){
                    interSectionArray.push_back(nums1[i]);
                }
                else if ( interSectionArray.size() != 0 && interSectionArray.back() != nums1[i] ){
                    interSectionArray.push_back(nums1[i]);
                }
                i++;j++;
            }
        }
        return interSectionArray;
    }
};