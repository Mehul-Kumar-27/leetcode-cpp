/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        else
        {
            if (nums[0] > nums[1])
            {
                return 0;
            }
            else if (nums[nums.size() - 1] > nums[nums.size() - 2])
            {
                return nums.size() - 1;
            }

            int high = nums.size() - 2;
            int low = 1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if ((nums[mid] > nums[mid - 1]) && (nums[mid] > nums[mid + 1]))
                {
                    return mid;
                }
                else if ((nums[mid] > nums[mid - 1]) && nums[mid] < nums[mid + 1])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
// @lc code=end
