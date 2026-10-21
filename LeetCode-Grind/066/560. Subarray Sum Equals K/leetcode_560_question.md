# 560. Subarray Sum Equals K

**LeetCode:** [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)  
**Difficulty:** Medium · **Topics:** Array, Hash Table, Prefix Sum

## Problem Statement

Given an integer array `nums` and an integer `k`, return the number of non-empty contiguous subarrays whose sum equals `k`.

## Examples

**Example 1**  
Input: `nums = [1,1,1], k = 2`  
Output: `2`  
Explanation: The two matching subarrays are `[1,1]` at indices `(0,1)` and `(1,2)`.

**Example 2**  
Input: `nums = [1,2,3], k = 3`  
Output: `2`  
Explanation: The matching subarrays are `[1,2]` and `[3]`.

## Constraints

- `1 <= nums.length <= 2 * 10^4`
- `-1000 <= nums[i] <= 1000`
- `-10^7 <= k <= 10^7`

## Approach: Prefix Sum + Hash Map

Maintain a running prefix sum `sum`. A subarray ending at the current index has sum `k` when an earlier prefix sum equals `sum - k`.

The map `hash[p]` stores how many times prefix sum `p` has occurred.

1. Initialize `hash[0] = 1` to account for subarrays beginning at index `0`.
2. Add the current value to `sum`.
3. Add `hash[sum - k]` to the answer if that prefix sum exists.
4. Record the current prefix sum with `hash[sum]++`.

See [`leetcode_560_explanation.md`](leetcode_560_explanation.md) for the C++ code, dry runs, and complexity analysis.
