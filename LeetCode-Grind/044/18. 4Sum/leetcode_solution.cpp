class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int first = j + 1;
                int second = n - 1;

                while (first < second)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[first] + nums[second];

                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[first], nums[second]});

                        first++;
                        second--;

                        while (first < second && nums[first] == nums[first - 1])
                        {
                            first++;
                        }

                        while (first < second && nums[second] == nums[second + 1])
                        {
                            second--;
                        }
                    }

                    else if (sum < target)
                    {
                        first++;
                    }
                    else
                    {
                        second--;
                    }
                }
            }
        }
        return ans;
    }
};