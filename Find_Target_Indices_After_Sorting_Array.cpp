/*
https://leetcode.com/problems/find-target-indices-after-sorting-array/description/

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.
*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<int> ans;

        for(int i = 0; i<len; i++){
            if(nums[i] == target)
                ans.push_back(i);
        }
        return ans;
    }
};