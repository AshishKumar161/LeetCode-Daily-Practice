# LeetCode 88 - Merge Sorted Array

## Question

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`.

Merge `nums1` and `nums2` into one sorted array. The result must be stored inside `nums1`.

`nums1` has length `m + n`; its first `m` elements are valid values and its last `n` elements are empty positions represented by `0`.

## Example 1

```text
Input: nums1 = [1,2,3,0,0,0], m = 3
       nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

## Example 2

```text
Input: nums1 = [1], m = 1
       nums2 = [], n = 0
Output: [1]
```

## Example 3

```text
Input: nums1 = [0], m = 0
       nums2 = [1], n = 1
Output: [1]
```

## Constraints

- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `nums1` and `nums2` are sorted in non-decreasing order.
