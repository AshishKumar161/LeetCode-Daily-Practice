# 152. Maximum Product Subarray

**LeetCode:** [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)  
**Difficulty:** Medium · **Topics:** Array, Dynamic Programming

## Problem Statement

Given an integer array `nums`, find a contiguous, non-empty subarray with the largest product and return that product.

## Examples

**Example 1**

Input: `nums = [2,3,-2,4]`  
Output: `6`  
Explanation: `[2,3]` has product `2 * 3 = 6`, the maximum.

**Example 2**

Input: `nums = [-2,0,-1]`  
Output: `0`  
Explanation: The subarray `[0]` has product `0`, which is greater than either negative single-element product.

## Constraints

- `1 <= nums.length <= 2 * 10^4`
- `-10 <= nums[i] <= 10`
- The product of any subarray fits in a 32-bit integer.

## Approach

The submitted solution scans from both directions:

1. Maintain a prefix product `pref` scanning left to right.
2. Maintain a suffix product `suff` scanning right to left.
3. Reset a running product to `1` after it becomes `0`, so the next nonzero segment can start.
4. At each index, update the answer with the largest of `max_prod`, `pref`, and `suff`.

Scanning both ways accounts for negative numbers that can change the sign of a product.

See [`leetcode_152_explanation.md`](leetcode_152_explanation.md) for the C++ code, dry run, and complexity analysis.
