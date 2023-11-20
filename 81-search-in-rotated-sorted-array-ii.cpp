/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool binarySearch(vector<int> nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return true;
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

        return false;
    }
    bool search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            if ((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                high--;
                low++;
            }
            // left part is sorted
            else if (nums[low] <= nums[mid])
            {
                // Find wether the target is available in the sorted half
                if ((nums[low] <= target) && (nums[mid] > target))
                {
                    // Element can be found in the sorted portion
                    return binarySearch(nums, low, mid, target);
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                // Right part is sorted
                // Find wether the target is available in the sorted half
                if ((nums[mid] < target) && (nums[high] >= target))
                {

                    // Element can be found in the sorted portion
                    return binarySearch(nums, mid, high, target);
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 1, 3};

    Solution s = Solution();

    cout << s.search(nums, 3) << endl;
    return 0;
}

// @lc code=end
