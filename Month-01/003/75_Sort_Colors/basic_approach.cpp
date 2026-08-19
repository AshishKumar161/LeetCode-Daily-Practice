#include <iostream>
using namespace std;

void sortt(int arr[], int n)
{
    int one = 0;
    int two = 0;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero++ ;
        }

        else if (arr[i] == 1)
        {
            one++;
        }

        else
        {
            two++ ;
        }
    }

    int index = 0 ; 

    for (int  i = 0; i < zero ; i++)
    {
        arr[index] = 0 ;
        index++ ;
        
    }

    for (int  i = 0; i < one ; i++)
    {
        arr[index] = 1 ;
        index++ ;
    }

    for (int  i = 0; i < two ; i++)
    {
        arr[index] = 2 ;
        index++ ;

    }
}




int main()
{
    system("cls");
    int arr[10] = {0, 0, 1, 2, 1, 0, 1, 2, 0, 1};
    int n = 10;

    sortt(arr , n) ;

    for (int  i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;

    }
    

    system("pause");
    system("cls");
    return 0;
}