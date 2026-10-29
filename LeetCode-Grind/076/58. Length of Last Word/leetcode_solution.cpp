class Solution {
    public:
        int lengthOfLastWord(string s) {
            int i = s.size() - 1;
            int count = 0;
    
            // Skip trailing spaces
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
    
            // Count characters in the last word
            while (i >= 0 && s[i] != ' ') {
                count++;
                i--;
            }
    
            return count;
        }
    };