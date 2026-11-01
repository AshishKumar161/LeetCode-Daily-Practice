# LeetCode 1353 — Maximum Number of Events That Can Be Attended

**Difficulty:** Medium  
**Topics:** Array, Greedy, Sorting, Heap (Priority Queue)

## Problem Statement

You are given an array `events`, where `events[i] = [startDayi, endDayi]`. Event `i` starts on `startDayi` and ends on `endDayi`.

You can attend event `i` on any day `d` satisfying:

```text
startDayi <= d <= endDayi
```

You can attend at most one event on any day. Return the maximum number of events you can attend.

## Example 1

**Input**
```text
events = [[1,2],[2,3],[3,4]]
```
**Output**
```text
3
```
**Explanation:** Attend `[1,2]` on Day 1, `[2,3]` on Day 2, and `[3,4]` on Day 3.

```text
Day:       1       2       3       4
Event 1:  [=======]
Attend:    YES
Event 2:          [=======]
Attend:            YES
Event 3:                  [=======]
Attend:                    YES
```

## Example 2

**Input**
```text
events = [[1,2],[2,3],[3,4],[1,2]]
```
**Output**
```text
4
```
**Explanation:** One valid schedule is to attend the two `[1,2]` events on Days 1 and 2, `[2,3]` on Day 3, and `[3,4]` on Day 4.

## Constraints

- `1 <= events.length <= 10^5`
- `events[i].length == 2`
- `1 <= startDayi <= endDayi <= 10^5`

## Function Signature

```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events);
};
```

## Important Rules

1. Both start and end days are inclusive.
2. Only one event can be attended per day.
3. Events do not need to be attended in input order.
4. Maximize the number of events attended.
