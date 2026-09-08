class Solution {
public:
    bool isSubsequence(string s, string t) {
        int first = 0 ;
        int second = 0 ;

        while (second < t.size())
        {
            if(s[first] == t[second])
            {
                first++ ; 
                second++ ;
            }
            else
            {
                second++ ;
            }
        }
        if (first == s.size())
        {
            return true ;
        }

        return false ;
    }
};