# 163. Count Subarrays with Given XOR K

**Practice:** [takeUforward — Count subarrays with given XOR K](https://takeuforward.org/practice/dsa/count-subarrays-with-given-xor-k)  
**Topics:** Array, Prefix XOR, Hash Map

## Problem Statement

Given an integer array `nums` and an integer `k`, return the number of non-empty contiguous subarrays whose bitwise XOR equals `k`.

## Examples

**Example 1**

Input:
```text
nums = [4, 2, 2, 6, 4], k = 6
```
Output:
```text
4
```

**Example 2**

Input:
```text
nums = [5, 6, 7, 8, 9], k = 5
```
Output:
```text
2
```

## Approach: Prefix XOR + Hash Map

Let `xr` be the XOR of the current prefix (from index `0` to the current index). If an earlier prefix XOR is `x`, then the XOR of the subarray between that prefix and the current index is `xr ^ x`.

We need:
```text
xr ^ x = k
x = xr ^ k
```

For each element:
1. Update the prefix XOR: `xr ^= nums[i]`.
2. Find `x = xr ^ k`.
3. Add the number of times `x` has appeared before to the answer.
4. Record the current prefix XOR with `hash[xr]++`.

Initialize `hash[0] = 1` to count subarrays that begin at index `0`.

See [`leetcode_163_explanation.md`](leetcode_163_explanation.md) for the full C++ solution, dry run, and complexity analysis.
