class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        for (int i = 0, j = k - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        for (int i = k, j = n - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }

        return;
    }
};