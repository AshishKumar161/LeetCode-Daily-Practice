class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leader;

        int i = 0;

        while (i < n)
        {
            int store = i;

            for (int j = i; j < n; j++)
            {
                if (nums[store] < nums[j])
                {
                    store = j;
                }
            }
            leader.push_back(nums[store]);
            i = store + 1;
        }

        //  reverse(leader.begin(), leader.end());

        return leader;
    }
};