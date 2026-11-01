# LeetCode 1353 — Maximum Number of Events That Can Be Attended: Explanation

## Approach: Greedy + Sorting + Min-Heap

Your code uses three ideas:

1. **Sorting:** Process events in increasing order of start day.
2. **Min-Heap:** Keep events that have started and have not expired, ordered by end day.
3. **Greedy:** Each day, attend the available event that ends earliest.

The greedy rule is important: choosing the event with the earliest deadline first preserves events with later deadlines for future days.

## Complete C++ Code

```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());
        int count = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        long long startDay = 0;
        int idx = 0;

        while (idx < n || !pq.empty()) {
            if (pq.empty() && startDay < events[idx][0]) {
                startDay = events[idx][0];
            }

            while (idx < n && events[idx][0] <= startDay) {
                pq.push({events[idx][1], events[idx][0]});
                idx++;
            }

            while (!pq.empty() && pq.top().first < startDay) {
                pq.pop();
            }

            if (!pq.empty()) {
                pq.pop();
                count++;
                startDay++;
            }
        }

        return count;
    }
};
```

## 1. Count Events

```cpp
int n = events.size();
```
Stores the number of events.

## 2. Sort Events

```cpp
sort(events.begin(), events.end());
```

The event pairs are sorted lexicographically: first by start day, then by end day if start days are equal.

Example:

```text
Before: [[2,3], [1,2], [1,4], [3,4]]
After:  [[1,2], [1,4], [2,3], [3,4]]
```

This lets us add events to the heap in chronological order.

## 3. Initialize the Answer

```cpp
int count = 0;
```

`count` is the number of events attended. It increases whenever we choose an event for the current day.

## 4. Understand the Min-Heap

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

This is a min-heap of pairs. Your code inserts each event as:

```cpp
{endDay, startDay}
```

The smallest pair is at the top. Pair comparison is lexicographical, so the heap prioritizes the smallest end day first.

```cpp
pq.top().first
```

is the earliest ending day among the events currently in the heap.

## 5. Initialize Day and Event Index

```cpp
long long startDay = 0;
int idx = 0;
```

- `startDay`: the day currently being processed.
- `idx`: the next event in the sorted array that has not yet been inserted.

## 6. Main Loop

```cpp
while (idx < n || !pq.empty())
```

Continue while there are unprocessed events or events waiting in the heap.

If the heap is empty, the next event must still exist (`idx < n`), because otherwise the loop condition would be false.

## 7. Jump Over Empty Days

```cpp
if (pq.empty() && startDay < events[idx][0]) {
    startDay = events[idx][0];
}
```

If no event is available, jump directly to the next event's start day instead of checking every empty day.

Example:

```text
Current day = 1
Heap = empty
Next event = [5,8]

Jump directly to Day 5.
```

## 8. Insert Events That Have Started

```cpp
while (idx < n && events[idx][0] <= startDay) {
    pq.push({events[idx][1], events[idx][0]});
    idx++;
}
```

Insert all events whose start day is less than or equal to the current day.

The condition uses `<=` because an event is available on its start day.

The heap stores `{endDay, startDay}`. Then `idx++` moves to the next event so the same event is not inserted twice.

## 9. Remove Expired Events

```cpp
while (!pq.empty() && pq.top().first < startDay) {
    pq.pop();
}
```

An event is expired when its end day is smaller than the current day.

Example:

```text
Current day = 4
Event = [1,3]
```

It cannot be attended on Day 4, so remove it.

Why `<` and not `<=`? An event ending on the current day is still valid that day:

```text
Current day = 3
Event = [1,3]
```

It can still be attended on Day 3.

## 10. Attend the Earliest-Ending Event

```cpp
if (!pq.empty()) {
    pq.pop();
    count++;
    startDay++;
}
```

If a valid event remains:

1. `pq.pop()` removes the event with the earliest end day.
2. `count++` records one attended event.
3. `startDay++` advances to the next day.

Only one event can be attended per day, so we select exactly one.

## 11. Return the Result

```cpp
return count;
```

When no unprocessed events and no available events remain, return the total attended count.

---

# Complete Dry Run — Example 1

Input:

```text
events = [[1,2], [2,3], [3,4]]
```

After sorting:

```text
Index   Start   End
  0       1      2
  1       2      3
  2       3      4
```

Initial state:

```text
startDay = 0
idx = 0
count = 0
pq = empty
```

### Iteration 1 — Day 1

The heap is empty, so jump to the first event's start day:

```text
startDay = 1
```

Insert events with `start <= 1`:

```text
Insert [1,2]
Heap: {(2,1)}
idx = 1
```

No event is expired. Pop the earliest-ending event:

```text
Attend [1,2] on Day 1
count = 1
startDay = 2
```

### Iteration 2 — Day 2

Insert events with `start <= 2`:

```text
Insert [2,3]
Heap: {(3,2)}
idx = 2
```

It has not expired. Attend it:

```text
Attend [2,3] on Day 2
count = 2
startDay = 3
```

### Iteration 3 — Day 3

Insert events with `start <= 3`:

```text
Insert [3,4]
Heap: {(4,3)}
idx = 3
```

Attend it:

```text
Attend [3,4] on Day 3
count = 3
startDay = 4
```

Now `idx == n` and the heap is empty, so the loop ends.

**Output: 3**

## Visual Schedule

```text
             Day 1       Day 2       Day 3       Day 4
Event A:     [1-----------2]
Attend:       YES
Event B:                 [2-----------3]
Attend:                    YES
Event C:                             [3-----------4]
Attend:                                YES
```

## Dry Run — Example 2

Input:

```text
events = [[1,2], [2,3], [3,4], [1,2]]
```

Sorted:

```text
[[1,2], [1,2], [2,3], [3,4]]
```

| Day | Available event(s) | Selected event | Count |
|---:|---|---|---:|
| 1 | Two `[1,2]` events | One `[1,2]` | 1 |
| 2 | Remaining `[1,2]`, `[2,3]` | `[1,2]` | 2 |
| 3 | `[2,3]`, `[3,4]` | `[2,3]` | 3 |
| 4 | `[3,4]` | `[3,4]` | 4 |

Output:

```text
4
```

## Why Does the Greedy Strategy Work?

Suppose these events are all available on Day 1:

```text
Event A: [1,2]
Event B: [1,5]
Event C: [1,8]
```

Choosing Event C first is risky because A and B have earlier deadlines.

Instead:

```text
Day 1 -> Event A
Day 2 -> Event B
Day 3 -> Event C
```

Selecting the event with the earliest end day first preserves events with later deadlines for future days. This is the greedy choice used by the solution.

## Complexity Analysis

Let `n` be the number of events.

| Operation | Complexity |
|---|---:|
| Sort events | `O(n log n)` |
| Insert each event into heap | `O(log n)` per event |
| Remove each event from heap | `O(log n)` per event |
| All heap insertions/removals | `O(n log n)` |

Each event is inserted at most once and removed at most once. The current day advances after an event is attended and jumps over empty ranges.

**Time Complexity: `O(n log n)`**  
**Space Complexity: `O(n)`** — the heap can contain up to `n` events.

## Interview Notes

- Sort events by start day.
- Store `{endDay, startDay}` in the min-heap.
- `pq.top().first` gives the earliest ending day.
- Insert events while `events[idx][0] <= startDay`.
- Remove expired events while `pq.top().first < startDay`.
- Attend one event, increment `count`, and move to the next day.
- If the heap is empty, jump to the next event's start day.

## Core Greedy Rule

```text
For each day:
    Add every event that has started.
    Remove every event that has expired.
    Attend the available event with the earliest end day.
```
