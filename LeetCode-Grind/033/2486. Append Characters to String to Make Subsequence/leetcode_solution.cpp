class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0 ;
        int second = 0 ;
        while (first < s.size() && second < t.size())
        {
            if(s[first] ==  t[second])
            {
                first++ ;
                second++ ;
            }
            else
            {
                first++ ;
            }
        }
        return t.size() - second ;
    }
};