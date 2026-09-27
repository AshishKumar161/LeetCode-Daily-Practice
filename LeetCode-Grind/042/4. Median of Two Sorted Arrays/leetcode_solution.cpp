class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        int m = nums2.size() ;
        int n1 = 0 ;
        int m1 = 0 ;
        vector < int > nums3 ;

        while(n1 < n && m1 < m)
        {
            if (nums1[n1] < nums2[m1])
            {
                nums3.push_back(nums1[n1]) ;
                n1++;
            }
            else
            {
                nums3.push_back(nums2[m1]);
                m1++ ;
            }
        }

        while (n  > n1)
        {
            nums3.push_back(nums1[n1]) ;
            n1++ ;
        }
        while(m > m1)
        {
            nums3.push_back(nums2[m1]) ;
            m1++ ;
        }

        int n3 = nums3.size() ;

        int mid = n3 / 2 ;

        if (n3 % 2 == 1 )
        {
            return nums3[mid] ;
        }
        return (nums3[mid - 1] + nums3[mid]) / 2.0 ;

    }
};