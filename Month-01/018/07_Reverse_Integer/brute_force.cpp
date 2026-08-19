#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int reverseInteger(int x)
{
    bool negative = false;

    if (x < 0)
    {
        negative = true;
        x = -x;
    }

    string num = to_string(x);

    reverse(num.begin(), num.end());

    int ans = stoi(num);

    if (negative)
    {
        ans = -ans;
    }

    return ans;
}

int main()
{
    int x;

    cout << "Enter Number : ";
    cin >> x;

    cout << "Reverse = " << reverseInteger(x);

    return 0;
}