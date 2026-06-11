#include <stdio.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    int merged[m + n];
    int i = 0, j = 0, k = 0;

    // Merge the two sorted arrays
    while (i < m && j < n) {
        if (nums1[i] < nums2[j])
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }

    while (i < m)
        merged[k++] = nums1[i++];

    while (j < n)
        merged[k++] = nums2[j++];

    int total = m + n;

    // Find median
    if (total % 2 == 1) {
        return merged[total / 2];
    } else {
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    }
}