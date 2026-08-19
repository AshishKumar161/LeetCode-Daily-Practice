#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    string num = to_string(x);
    string rev = num;

    reverse(rev.begin(), rev.end());

    return num == rev;
}

int main()
{
    int x;

    cout << "Enter Number : ";
    cin >> x;

    if (isPalindrome(x))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}