#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxx = INT_MIN;

        for (int val : nums)
        {
            sum = sum + val;
            maxx = max(sum, maxx);

            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxx;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Subarray Sum = " << s.maxSubArray(nums) << endl;

    return 0;
}