class Solution
{
public:
    bool isPalindrome(int x)
    {

        // Negative numbers are not palindrome.
        // Numbers ending with 0 (except 0 itself) are not palindrome.
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int rev = 0;

        // Reverse only half of the number.
        while (x > rev)
        {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        // Even digits: x == rev
        // Odd digits : x == rev / 10 (ignore middle digit)
        return (x == rev) || (x == rev / 10);
    }
};