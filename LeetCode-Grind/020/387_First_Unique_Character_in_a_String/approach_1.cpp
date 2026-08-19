//                                         Hashing (Best Approach) (O(n))

class Solution
{
public:
    int firstUniqChar(string s)
    {

        int hash[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            hash[s[i] - 'a']++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (hash[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};