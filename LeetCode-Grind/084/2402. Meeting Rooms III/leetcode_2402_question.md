# LeetCode 2402 — Meeting Rooms III

**Difficulty:** Hard  
**Topics:** Array, Sorting, Heap (Priority Queue), Simulation

## Problem Statement

You are given an integer `n`. There are `n` rooms numbered from `0` to `n - 1`.

You are given a 2D integer array `meetings` where `meetings[i] = [starti, endi]` means that a meeting will be held during the half-open time interval `[starti, endi)`. All start times are unique.

Meetings are allocated as follows:

1. Each meeting uses the unused room with the lowest number.
2. If no room is available, the meeting is delayed until a room becomes free. The delayed meeting keeps the same duration as the original meeting.
3. When a room becomes unused, meetings with an earlier original start time are given priority.

Return the room number that held the most meetings. If multiple rooms held the same maximum number, return the lowest room number.

A half-open interval `[a, b)` includes `a` but does not include `b`.

## Example 1

**Input**
```text
n = 2
meetings = [[0,10], [1,5], [2,7], [3,4]]
```

**Output**
```text
0
```

**Explanation:**
- `[0,10)` starts in room `0`.
- `[1,5)` starts in room `1`.
- `[2,7)` cannot start because both rooms are busy. It waits for room `1`, which becomes free at time `5`. Its duration is `5`, so it runs from `5` to `10`.
- `[3,4)` waits until room `0` becomes free at time `10`. Its duration is `1`, so it runs from `10` to `11`.

```text
Room 0: [0,10) -> [10,11)     2 meetings
Room 1: [1,5)  -> [5,10)      2 meetings
```

Both rooms held two meetings, so return room `0` because it has the lower number.

## Example 2

**Input**
```text
n = 3
meetings = [[1,20], [2,10], [3,5], [4,9], [6,8]]
```

**Output:** `1`

**Explanation:** The first three meetings start in rooms `0`, `1`, and `2`. Meeting `[4,9)` waits for room `2` to become free at time `5`, so it runs until time `10`. Meeting `[6,8)` then waits until time `10`; rooms `1` and `2` are both free then, so room `1` is selected. Room `1` holds the most meetings.

## Constraints

- `1 <= n <= 100`
- `1 <= meetings.length <= 10^5`
- `meetings[i].length == 2`
- `0 <= starti < endi <= 5 * 10^5`
- All start times are unique.

## Function Signature

```cpp
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings);
};
```

## Important Rules

- Process meetings by original start time.
- If rooms are free, choose the lowest room number.
- If all rooms are busy, choose the room with the earliest ending time.
- If ending times tie, choose the lower room number.
- A delayed meeting keeps its original duration:
  `new_end = room_free_time + (original_end - original_start)`.
- Return the room with the most meetings; break ties by lowest room number.
