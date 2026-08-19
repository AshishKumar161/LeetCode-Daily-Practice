//                                    Hash Map + Queue (Streaming Approach)

class Solution
{
public:
    int firstUniqChar(string s)
    {

        unordered_map<char, int> freq;
        queue<int> q;

        for (int i = 0; i < s.length(); i++)
        {

            freq[s[i]]++;
            q.push(i);

            while (!q.empty() && freq[s[q.front()]] > 1)
            {
                q.pop();
            }
        }

        if (q.empty())
        {
            return -1;
        }

        return q.front();
    }
};