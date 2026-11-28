class Solution {
public:
    int mySqrt(int x) {
        int low = 0 ;
        int high = x ;

        while ( low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if (1ll * mid * mid == x)
            {
                return mid ;
            }
            
            if (1ll * mid * mid > x)
            {
                high = mid - 1 ;
            }

            if (1ll * mid * mid < x)
            {
                low  = mid  + 1 ;
            }
        }
        
        return high ;
    }
};