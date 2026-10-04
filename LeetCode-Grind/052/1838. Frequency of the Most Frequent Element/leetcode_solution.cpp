
class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            int max_val = 0;
            for (int num : nums) {
                if (num > max_val) {
                    max_val = num;
                }
            }
            
            vector<int> count(max_val + 1, 0);
            for (int num : nums) {
                count[num]++;
            }
            
            int index = 0;
            for (int i = 0; i <= max_val; i++) {
                while (count[i] > 0) {
                    nums[index] = i;
                    index++;
                    count[i]--;
                }
            }
            
            int left = 0;
            long long current_sum = 0;
            int max_freq = 0;
            
            for (int right = 0; right < nums.size(); right++) {
                current_sum += nums[right];
                
                long long window_size = right - left + 1;
                long long target = nums[right];
                
                while ((window_size * target) - current_sum > k) {
                    current_sum -= nums[left];
                    left++;
                    window_size = right - left + 1;
                }
                
                if (window_size > max_freq) {
                    max_freq = window_size;
                }
            }
            
            return max_freq;
        }
    };