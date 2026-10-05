class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> mp;
    
            int left = 0;
            int right = 0;
            int maxLength = 0;
    
            while (right < s.length()) {
    
                if (mp.find(s[right]) != mp.end()) {
                    left = max(left, mp[s[right]] + 1);
                }
    
                mp[s[right]] = right;
    
                maxLength = max(maxLength, right - left + 1);
    
                right++;
            }
    
            return maxLength;
        }
    };