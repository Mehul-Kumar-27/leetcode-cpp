/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int piviotIndex(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int n = high;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= nums[0] && nums[mid] >= nums[n])
            {
                // Higher Line
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return high;
    }
    int findMin(vector<int> &nums)
    {
        int piviot = piviotIndex(nums);

        return nums[piviot];
    }
};
// @lc code=end
