# 56. Merge Intervals

**LeetCode:** [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)  
**Difficulty:** Medium · **Topics:** Array, Sorting

## Problem Statement

Given an array of intervals where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals and return non-overlapping intervals that cover every input interval.

Intervals that meet at an endpoint are considered overlapping.

## Examples

**Example 1**  
Input: `[[1,3],[2,6],[8,10],[15,18]]`  
Output: `[[1,6],[8,10],[15,18]]`

**Example 2**  
Input: `[[1,4],[4,5]]`  
Output: `[[1,5]]`

**Example 3**  
Input: `[[4,7],[1,4]]`  
Output: `[[1,7]]`

## Constraints

- `1 <= intervals.length <= 10^4`
- Each interval contains exactly two values.
- `0 <= start_i <= end_i <= 10^4`

## Approach

1. Sort intervals by start value.
2. Keep a result vector `ans`.
3. If the result is empty or the current start is greater than the last merged end, add a new interval.
4. Otherwise, merge by updating the last end to `max(last end, current end)`.
5. Return `ans`.

See [`leetcode_56_explanation.md`](leetcode_56_explanation.md) for the full code, dry run, and complexity analysis.
