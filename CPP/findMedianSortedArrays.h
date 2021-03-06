#ifndef FINDMEDIANSORTEDARRAYS_H_INCLUDED
#define FINDMEDIANSORTEDARRAYS_H_INCLUDED

#include <vector>
#include <climits>

#endif // FINDMEDIANSORTEDARRAYS_H_INCLUDED

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int L1, L2, R1, R2, c1, c2, low = 0, high = 2 * n;
        while(low <= high){
            c1 = (low + high) / 2;
            c2 = (m + n ) - c1;
            L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            R1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            R2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (L1 > R2){
                high = c1 - 1;
            }else if (L2 > R1){
                low = c1 + 1;
            }else{
                break;
            }
        }

        return (max(L1, L2) + min(R1, R2)) / 2.0;
    }
};
