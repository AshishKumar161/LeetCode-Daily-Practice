#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector <int> & nums) {
        int ans = 0 ;

        for (int i : nums) {
            ans ^= i ;
        }

        return ans ;
    }
};

int main() {
    Solution s;

    vector <int> nums = {4, 1, 2, 1, 2} ;

    cout << "Single Number = " << s.singleNumber(nums) << "\n" ;

    return 0;
}