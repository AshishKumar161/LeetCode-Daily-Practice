#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortColors(vector <int> &nums)
{
    int n = nums.size() ;

    int low = 0 ;
    int midd = 0 ;
    int high = n - 1 ;

    while (midd <= high)
    {
        if (nums[midd] == 0)
        {
            swap(nums[low], nums[midd]) ;
            low++ ;
            midd++ ;
        }

        else if (nums[midd] == 1)
        {
            midd++ ;

        }

        else
        {
            swap(nums[high], nums[midd]) ; 
            high-- ;

        }
    }
}


int main()
{
    system("cls");

    vector <int> nums = {0, 1, 0} ;

    sortColors(nums) ;

    cout << "Sorted Array: " ;
    for (int  i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " " ;
    }

    cout << "\n" ;

    system("pause");
    system("cls");
    return 0;
}