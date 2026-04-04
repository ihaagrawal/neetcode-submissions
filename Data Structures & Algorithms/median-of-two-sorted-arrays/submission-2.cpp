class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size(), m = nums2.size();

        int l = 0, h = n;

        while (l <= h) {
            int px = (l + h) / 2;
            int py = (n + m + 1) / 2 - px;

            int x1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int x2 = (px == n) ? INT_MAX : nums1[px];

            int x3 = (py == 0) ? INT_MIN : nums2[py - 1];
            int x4 = (py == m) ? INT_MAX : nums2[py];

            if (x1 <= x4 && x3 <= x2) {
                if ((n + m) % 2 == 1) return max(x1, x3);
                else return (max(x1, x3) + min(x2, x4)) / 2.0;
            }else if (x1 > x4) h = px - 1;
            else l = px + 1;
        }

        return -1;
    }
};