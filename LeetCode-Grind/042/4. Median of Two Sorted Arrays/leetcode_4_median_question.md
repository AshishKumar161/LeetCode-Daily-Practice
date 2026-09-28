# LeetCode 4 - Median of Two Sorted Arrays

## Question

Given two sorted arrays `nums1` and `nums2` of size `m` and `n`
respectively, return the **median** of the two sorted arrays.

The overall run time complexity should be:

``` text
O(log(m + n))
```

## Example 1

``` text
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
```

Merged order: `[1,2,3]`, so the median is `2`.

## Example 2

``` text
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
```

Merged order: `[1,2,3,4]`.

``` text
(2 + 3) / 2 = 2.5
```

## Topics

-   Array
-   Binary Search
-   Partition
