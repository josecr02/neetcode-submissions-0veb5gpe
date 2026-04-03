class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // inputs are sorted
        // we can solve in O(n+m) by having 2 pointers i, j and simulate merging until (len1 + len2) / 2 + 1
        // and then taking the 2 or 1 medians.

        // but we do it in O(log(m + n)) time and space
        // “What is the k-th smallest element in the union of two sorted arrays?”

        int left = (nums1.size() + nums2.size() + 1) / 2;
        int right = (nums1.size() + nums2.size() + 2) / 2;
        return (getKth(nums1, nums1.size(), nums2, nums2.size(), left, 0, 0) +
                getKth(nums1, nums1.size(), nums2, nums2.size(), right, 0, 0)) / 2.0;
    } 

    int getKth(vector<int>& a, int m, vector<int>& b, int n, int k, int aStart, int bStart) {
        if (m > n) {
            return getKth(b, n, a, m, k, bStart, aStart);
        }
        if (m == 0) { // A is empty so the kth smallest element is at B k - 1.
            return b[bStart + k - 1];
        }
        if (k == 1) { // just choose between the intial values since theyre sorted
            return min(a[aStart], b[bStart]);
        }

        int i = min(m, k / 2);
        int j = min(n, k / 2);

        if (a[aStart + i - 1] > b[bStart + j - 1]) { // the first j elements of B cannot have the kth smallest
            return getKth(a, m, b, n - j, k - j, aStart, bStart + j);
        } else {
            return getKth(a, m - i, b, n, k - i, aStart + i, bStart);
        }
    }
};
