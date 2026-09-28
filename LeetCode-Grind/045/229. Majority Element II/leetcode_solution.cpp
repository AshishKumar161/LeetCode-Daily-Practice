class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> hash;

        for (int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
        }

        vector<int> ans;

        for (auto x : hash)
        {
            if (x.second > n / 3)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};