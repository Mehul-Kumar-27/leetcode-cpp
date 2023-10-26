/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int lowerIndex(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() -1;

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                ans = mid;
                high = mid -1;
            }else if( nums[mid] > target){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }

        return ans;
    }

    int upperIndex(vector<int>& nums, int target){
               int low = 0;
        int high = nums.size() -1;

        int ans = -1;

        while(low <= high){
             int mid = low + (high - low)/2;

            if(nums[mid] == target){
                ans = mid;
                low = mid +1;
            }else if( nums[mid] > target){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.empty()) {
            return result;
        }
        
        int low  = 0 ; 
        int high = nums.size() -1;

        result[0] = lowerIndex(nums, target);
        result[1] = upperIndex(nums, target);

        return result;


    }
};
// @lc code=end

