/*https://leetcode.com/problems/merge-sorted-array/description/
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r1 = m-1;
        int r2 = n-1;
        int w = m+n-1;

        while(r1>=0 && r2>=0){
            if(nums1[r1] >= nums2[r2]){
                nums1[w--] = nums1[r1--];
            }
            else if(nums1[r1] < nums2[r2]){
                nums1[w--] = nums2[r2--];
            }
        }
        while(r1>=0){
            nums1[w--] = nums1[r1--];
        }
        while(r2>=0){
            nums1[w--] = nums2[r2--];
        }

    }
};