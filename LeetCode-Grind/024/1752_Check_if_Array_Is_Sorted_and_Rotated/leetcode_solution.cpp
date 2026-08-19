class Solution
{
public:
    bool check(vector<int> &nums)
    {

        int n = nums.size();

        int store = -1;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                store = i;
                break;
            }
        }

        if (store == -1)
        {
            return true;
        }

        int k = store + 1;

        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        for (int i = 0, j = n - k - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        for (int i = n - k, j = n - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};