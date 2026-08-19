class Solution
{
public:
    bool isPalindrome(int x)
    {
        double reverse = 0;
        int orignal = x;
        if (x < 0)
        {
            return false;
        }
        while (x != 0)
        {
            reverse = (reverse * 10) + x % 10;
            x /= 10;
        }

        // if(reverse == orignal)
        // {
        //     return true ;
        // }
        // else
        // {
        //     return false ;
        // }

        return reverse == orignal;
    }
};