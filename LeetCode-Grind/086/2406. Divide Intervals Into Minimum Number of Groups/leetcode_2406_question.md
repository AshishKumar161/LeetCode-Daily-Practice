# LeetCode 2406 — Divide Intervals Into Minimum Number of Groups

**Difficulty:** Medium  
**Topics:** Array, Greedy, Sorting, Heap, Sweep Line

## Problem Statement

You are given a 2D integer array `intervals` where `intervals[i] = [lefti, righti]` represents an inclusive interval from `lefti` to `righti`.

Divide the intervals into one or more groups so that:
- Each interval belongs to exactly one group.
- No two intervals in the same group intersect.

Return the minimum number of groups required.

Two intervals intersect if they share at least one integer. For example, `[1,5]` and `[5,8]` intersect because both contain `5`.

## Example 1

**Input**
```text
intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
```
**Output**
```text
3
```
**Explanation:** One valid grouping is:
```text
Group 1: [1,5], [6,8]
Group 2: [1,10]
Group 3: [2,3], [5,10]
```
It can be shown that fewer than three groups are not enough.

## Example 2

**Input**
```text
intervals = [[1,3],[5,6],[8,10],[11,13]]
```
**Output**
```text
1
```
**Explanation:** None of the intervals overlap, so all can be placed in one group.

## Constraints

- `1 <= intervals.length <= 10^5`
- `intervals[i].length == 2`
- `1 <= lefti <= righti <= 10^6`

## C++ Function Signature

```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals);
};
```

## Important Detail: Inclusive Intervals

```text
[1,5] and [5,8] -> intersect
[1,5] and [6,8] -> do not intersect
```

A group can be reused only when its previous interval ends **strictly before** the next interval starts: `previousEnd < currentStart`.
