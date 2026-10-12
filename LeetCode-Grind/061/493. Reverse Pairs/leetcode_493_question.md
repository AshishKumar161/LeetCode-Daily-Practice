# 493. Reverse Pairs

**LeetCode:** [493. Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)  
**Difficulty:** Hard  
**Topics:** Array, Divide and Conquer, Merge Sort

## Problem Statement

Given an integer array `nums`, return the number of reverse pairs.

A pair `(i, j)` is a reverse pair when:
- `0 <= i < j < nums.length`
- `nums[i] > 2 * nums[j]`

## Examples

**Example 1**

Input: `nums = [1,3,2,3,1]`  
Output: `2`

The reverse pairs are `(1,4)` and `(3,4)` because `3 > 2 * 1`.

**Example 2**

Input: `nums = [2,4,3,5,1]`  
Output: `3`

The reverse pairs are `(1,4)`, `(2,4)`, and `(3,4)`.

## Approach: Modified Merge Sort

1. Recursively count reverse pairs in the left half.
2. Recursively count reverse pairs in the right half.
3. Count cross-half pairs while both halves are sorted.
4. Merge the sorted halves.

For each left-side value `nums[i]`, move pointer `j` through the right half while `nums[i] > 2LL * nums[j]`. Every right-side element before `j` satisfies the condition, so add `j - (mid + 1)` to the count.

`2LL` promotes the multiplication to `long long` to prevent integer overflow.

See [`leetcode_493_explanation.md`](leetcode_493_explanation.md) for the code, detailed logic, dry run, and complexity.
