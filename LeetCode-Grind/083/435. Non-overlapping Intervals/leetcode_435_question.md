# LeetCode 435 — Non-overlapping Intervals

**Difficulty:** Medium | **Topics:** Array, Greedy, Sorting, Dynamic Programming

## Problem Statement
You are given an array of intervals where `intervals[i] = [starti, endi]`. Return the **minimum number of intervals you need to remove** to make the rest non-overlapping.

Intervals that only touch at a point are non-overlapping. For example, `[1,2]` and `[2,3]` do not overlap.

## Example 1
**Input**
```text
intervals = [[1,2], [2,3], [3,4], [1,3]]
```
**Output**
```text
1
```
**Explanation:** Remove `[1,3]`. The remaining intervals `[1,2]`, `[2,3]`, and `[3,4]` do not overlap.

```text
[1,2]:  1 ---- 2
[2,3]:         2 ---- 3
[3,4]:                3 ---- 4
[1,3]:  1 ------------ 3

Keep:   [1,2] -> [2,3] -> [3,4]
Remove: [1,3]
```

## Example 2
**Input**
```text
intervals = [[1,2], [1,2], [1,2]]
```
**Output:** `2`

**Explanation:** Keep one interval and remove the other two.

## Example 3
**Input**
```text
intervals = [[1,2], [2,3]]
```
**Output:** `0`

**Explanation:** The intervals only touch at endpoint `2`, so they are non-overlapping.

## Constraints
- `1 <= intervals.length <= 2 * 10^5`
- `intervals[i].length == 2`
- `-5 * 10^4 <= starti < endi <= 5 * 10^4`

## Function Signature
```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals);
};
```

## Important Rule
The next interval can be kept when:
```text
next_interval.start >= previous_interval.end
```
Equality is allowed because touching intervals are non-overlapping.
