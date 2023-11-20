#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mid == 0)
            {   
                if(nums.size() == 1){
                    return nums[0];
                }
                if (nums[0] != nums[1])
                {
                    return nums[0];
                }
            }

            else if (mid == nums.size() - 1)
            {
                if (nums[mid] != nums[nums.size() - 2])
                {
                    return nums[mid];
                }
            }
            else
            {
                if (mid % 2 == 0)
                {
                    if ((mid >= 1 && mid <= nums.size() - 2) && (nums[mid] != nums[mid + 1]) && (nums[mid] != nums[mid - 1]))
                    {
                        return nums[mid];
                    }
                    else if ((mid >= 1 && mid <= nums.size() - 2) && (nums[mid] == nums[mid - 1]))
                    {
                        high = mid - 1;
                    }

                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if ((mid >= 1 && mid <= nums.size() - 2) && (nums[mid] != nums[mid + 1]) && (nums[mid] != nums[mid - 1]))
                    {
                        return nums[mid];
                    }
                    else if ((mid >= 1 && mid <= nums.size() - 2) && (nums[mid] == nums[mid - 1]))
                    {

                        low = mid + 1;
                    }

                    else
                    {
                        high = mid - 1;
                    }
                }
            }
        }

        return -1;
    }
};
int main(int argc, char const *argv[])
{
    Solution s = Solution();

    vector<int> nums = {1};

    cout << s.singleNonDuplicate(nums);
    return 0;
}
