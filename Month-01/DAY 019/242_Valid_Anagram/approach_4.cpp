//                                          Hash Map with Erasing Zero Counts

class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        if (s.length() != t.length())
            return false;

        unordered_map<char, int> mp;

        for (char ch : s)
            mp[ch]++;

        for (char ch : t)
        {
            mp[ch]--;

            if (mp[ch] == 0)
                mp.erase(ch);
        }

        return mp.empty();
    }
};