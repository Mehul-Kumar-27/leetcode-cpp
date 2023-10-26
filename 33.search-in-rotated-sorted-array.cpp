/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int piviotIndex(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;
        int index = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid])
            {
                // Left Part Is sorted.
                if (ans > nums[low])
                {
                    index = low;
                    ans = nums[low];
                }

                low = mid + 1;
            }
            else
            {
                // Right Part is sorted
                if (ans > nums[mid])
                {
                    ans = nums[mid];
                    index = mid;
                }

                high = mid - 1;
            }
        }

        return index;
    }
    int binarySearch(vector<int> &nums, int target, int low, int high)
    {

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
    int search(vector<int> &nums, int target)
    {

        if (nums.size() == 0)
        {
            return -1;
        }

        if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }

        int n = nums.size() - 1;
        int piviot = piviotIndex(nums);

        if (nums[piviot] == target)
        {
            return piviot;
        }
        else if (nums[piviot] < target && target <= nums[n])
        {
            return binarySearch(nums, target, piviot, n);
        }
        else
        {
            return binarySearch(nums, target, 0, piviot - 1);
        }
    }
};
// @lc code=end
