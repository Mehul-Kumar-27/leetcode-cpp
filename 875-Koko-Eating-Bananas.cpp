#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &piles, int h, int bananaConsumedLimit)
    {
        int hoursConsumed = 1;
        int bananasConsumed = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            if (piles[i] + bananasConsumed <= bananaConsumedLimit)
            {
                bananasConsumed = bananasConsumed + piles[i];
            }
            else
            {
                hoursConsumed++;

                if (hoursConsumed > h || piles[i] > bananaConsumedLimit)
                {
                    return false;
                }

                bananasConsumed = piles[i];
            }
        }

        return true;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxHours = accumulate(piles.begin(), piles.end(), 0);
        cout << maxHours << " LL ";
        int minimumHours = 0;
        int ans = 0;

        while (minimumHours <= maxHours)
        {
            int mid = minimumHours + (maxHours - minimumHours) / 2;
            if (isPossible(piles, h, mid))
            {
                ans = mid;
                maxHours = mid - 1;
            }
            else
            {
                minimumHours = mid + 1;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> piles = {3, 6, 7, 11};

    Solution s = Solution();

    cout << s.minEatingSpeed(piles, 8);
    return 0;
}
