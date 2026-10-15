# 128. Longest Consecutive Sequence

**LeetCode:** [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)  
**Difficulty:** Medium · **Topics:** Array, Hash Table

## Problem Statement

Given an unsorted integer array `nums`, return the length of the longest sequence of consecutive elements. The sequence does not need to appear consecutively in the input array. Your algorithm must run in `O(n)` time.

## Examples

**Example 1**  
Input: `nums = [100,4,200,1,3,2]`  
Output: `4`  
Explanation: The longest sequence is `[1,2,3,4]`.

**Example 2**  
Input: `nums = [0,3,7,2,5,8,4,6,0,1]`  
Output: `9`  
Explanation: The longest sequence is `[0,1,2,3,4,5,6,7,8]`.

**Example 3**  
Input: `nums = [1,0,1,2]`  
Output: `3`  
Explanation: The longest sequence is `[0,1,2]`; duplicates do not count twice.

## Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Approach: Hash Set

1. Insert all values into an `unordered_set`, removing duplicates.
2. For each unique number, check whether `num - 1` exists.
3. If it does not, `num` is the beginning of a consecutive sequence.
4. Count forward while `curr + 1` exists.
5. Update the maximum sequence length.

See [`leetcode_128_explanation.md`](leetcode_128_explanation.md) for the C++ solution, dry run, and complexity analysis.
