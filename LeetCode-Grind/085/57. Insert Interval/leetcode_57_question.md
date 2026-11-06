# LeetCode 57 — Insert Interval

**Difficulty:** Medium  
**Topics:** Array, Sorting

## Problem Statement

You are given an array of non-overlapping intervals `intervals`, where `intervals[i] = [starti, endi]`. The intervals are sorted in ascending order by their start times.

You are also given an interval `newInterval = [start, end]`.

Insert `newInterval` into `intervals` so that the resulting intervals are still sorted in ascending order and do not overlap. Merge overlapping intervals if necessary.

Return the resulting array of intervals.

**Note:** You do not need to modify the input array in-place. You may create and return a new array.

## Example 1

**Input:**
```text
intervals = [[1,3],[6,9]]
newInterval = [2,5]
```

**Output:**
```text
[[1,5],[6,9]]
```

**Explanation:** The new interval `[2,5]` overlaps with `[1,3]`. Merge them to form `[1,5]`. The interval `[6,9]` does not overlap, so it remains unchanged.

## Example 2

**Input:**
```text
intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]
```

**Output:**
```text
[[1,2],[3,10],[12,16]]
```

**Explanation:** The new interval `[4,8]` overlaps with `[3,5]`, `[6,7]`, and `[8,10]`. Merge these intervals into `[3,10]`. The intervals `[1,2]` and `[12,16]` remain unchanged.

## Constraints

- `0 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 10^5`
- `intervals` is sorted by starting time in ascending order.
- `intervals` contains no overlapping intervals.
- `newInterval.length == 2`
- `0 <= start <= end <= 10^5`

## C++ Function Signature

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
};
```

## Key Observation

The original intervals are already sorted and non-overlapping. We can solve the problem in one linear traversal:

1. Copy all intervals that are completely before `newInterval`.
2. Merge every interval that overlaps `newInterval`.
3. Copy all intervals that come after the merged interval.
