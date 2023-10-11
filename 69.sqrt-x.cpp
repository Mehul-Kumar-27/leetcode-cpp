/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start

#include <iostream>
using namespace std;

class Solution
{
public:
    int calculate(int x, int start, int end)
    {
        if (start <= end)
        {
            int mid = start + (end - start) / 2;
            long long square = (long long)mid * mid; 

            if (square == x)
            {
                return mid;
            }
            else if (square < x)
            {
                return calculate(x, mid + 1, end);
            }
            else
            {
                return calculate(x, start, mid - 1);
            }
        }
        return end;
    }

    int mySqrt(int x)
    {
        return calculate(x, 0, x);
    }
};

// @lc code=end
