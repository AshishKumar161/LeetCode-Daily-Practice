# LeetCode 2402 — Meeting Rooms III: Explanation

## Your Approach: One Min-Heap + Temporary Vector

Your code uses one min-heap to store the state of every room. Each heap entry is:

```text
{ current_end_time, room_number, meetings_count }
```

The heap is a min-heap of vectors. C++ compares vectors lexicographically: it first compares ending times, then room numbers, then meeting counts. Therefore, the top entry is the room that becomes free earliest; if ending times tie, the lower room number comes first.

For every meeting, your code temporarily removes all rooms that are already free. It sorts those free rooms by room number and selects the smallest. If no room is free, it delays the meeting in the room that becomes free earliest.

## Your C++ Code

```cpp
class Solution {
public:
    int mostBooked(int rooms, vector<vector<int>>& meetings) {
        int n = meetings.size();
        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        // Create rooms
        for (int i = 0; i < rooms; i++) {
            pq.push({0, i, 0});
        }

        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < n; i++) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];
            long long duration = end - start;

            vector<vector<long long>> temp;

            // Find free rooms
            while (!pq.empty() && pq.top()[0] <= start) {
                temp.push_back(pq.top());
                pq.pop();
            }

            if (!temp.empty()) {
                sort(temp.begin(), temp.end(),
                     [](vector<long long>& a, vector<long long>& b) {
                         return a[1] < b[1];
                     });

                vector<long long> room = temp[0];

                long long roomidx = room[1];
                long long count = room[2] + 1;

                pq.push({end, roomidx, count});

                // Push remaining rooms back
                for (int i = 1; i < temp.size(); i++) {
                    pq.push(temp[i]);
                }
            }
            else {
                // All rooms are busy
                vector<long long> room = pq.top();
                pq.pop();

                long long newEnd = room[0] + duration;
                long long roomIdx = room[1];
                long long count = room[2] + 1;

                pq.push({newEnd, roomIdx, count});
            }
        }

        // Find the room with the maximum meeting count
        vector<long long> count(rooms, 0);

        while (!pq.empty()) {
            vector<long long> room = pq.top();
            pq.pop();
            count[room[1]] = room[2];
        }

        int ans = 0;
        for (int i = 0; i < rooms; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};
```

---

## 1. Create the Min-Heap

```cpp
priority_queue<
    vector<long long>,
    vector<vector<long long>>,
    greater<vector<long long>>
> pq;
```

Each entry contains:

```text
{end_time, room_index, meeting_count}
```

For example, `{10, 0, 3}` means room `0` becomes free at time `10` and has held three meetings.

Because the heap compares vectors lexicographically:

- Smaller ending time has priority.
- If ending times tie, smaller room number has priority.

## 2. Initialize Every Room

```cpp
for (int i = 0; i < rooms; i++) {
    pq.push({0, i, 0});
}
```

All rooms are initially free at time `0`, and their meeting counts are zero.

For three rooms:

```text
{0,0,0}
{0,1,0}
{0,2,0}
```

## 3. Sort Meetings by Original Start Time

```cpp
sort(meetings.begin(), meetings.end());
```

This ensures that meetings are processed in the order required by the problem. The start times are unique, so sorting the pairs gives the correct order.

## 4. Read the Meeting and Its Duration

```cpp
long long start = meetings[i][0];
long long end = meetings[i][1];
long long duration = end - start;
```

For `[2,7]`:

```text
start = 2
end = 7
duration = 5
```

If this meeting is delayed, it must still take five time units.

## 5. Collect All Currently Free Rooms

```cpp
vector<vector<long long>> temp;

while (!pq.empty() && pq.top()[0] <= start) {
    temp.push_back(pq.top());
    pq.pop();
}
```

The first value of each heap entry is the time when that room becomes free.

A room is available when:

```text
room_end_time <= meeting_start_time
```

The equality is important. Since intervals are half-open, a meeting ending at time `5` releases the room for another meeting starting at time `5`.

Your code temporarily removes all free rooms because the heap is ordered by ending time, but the problem requires the lowest room number among all rooms that are already free.

## 6. Case One: At Least One Room Is Free

```cpp
if (!temp.empty())
```

If the temporary vector contains rooms, at least one room is available.

### Sort by Room Number

```cpp
sort(temp.begin(), temp.end(),
     [](vector<long long>& a, vector<long long>& b) {
         return a[1] < b[1];
     });
```

The second element is the room number.

For example:

```text
Before:
{7,2,4}
{10,0,3}
{8,1,2}

After sorting by room number:
{10,0,3}
{8,1,2}
{7,2,4}
```

Room `0` is selected, even though it became free later than rooms `1` and `2`. All three rooms are free at the current meeting's start time.

### Select the Room and Increase Its Count

```cpp
vector<long long> room = temp[0];

long long roomidx = room[1];
long long count = room[2] + 1;
```

`temp[0]` is the available room with the smallest room number.

### Schedule the Meeting on Time

```cpp
pq.push({end, roomidx, count});
```

Because the meeting starts on time, its ending time remains the original `end`.

### Restore the Other Free Rooms

```cpp
for (int i = 1; i < temp.size(); i++) {
    pq.push(temp[i]);
}
```

Only the first room was assigned the meeting. The other rooms are still free, so they must be returned to the heap unchanged.

## 7. Case Two: All Rooms Are Busy

```cpp
else {
    vector<long long> room = pq.top();
    pq.pop();
```

If `temp` is empty, no room is available at the meeting's original start time.

The heap top gives the room with the earliest ending time. If multiple rooms have the same ending time, lexicographical ordering chooses the lowest room number.

### Calculate the Delayed Ending Time

```cpp
long long newEnd = room[0] + duration;
```

This is a critical line.

The delayed meeting starts when the selected room becomes free:

```text
actual_start = previous_room_end_time
```

The duration must remain unchanged:

```text
new_end = actual_start + original_duration
```

Example:

```text
Original meeting = [2,7]
Original duration = 5

Selected room becomes free at time 10.

Actual meeting = [10,15)
newEnd = 10 + 5 = 15
```

Do not use the original `end` here because the meeting has been delayed.

### Update Count and Return the Room to the Heap

```cpp
long long roomIdx = room[1];
long long count = room[2] + 1;

pq.push({newEnd, roomIdx, count});
```

The room has held one more meeting, and its new availability time is `newEnd`.

---

## 8. Extract the Meeting Counts

```cpp
vector<long long> count(rooms, 0);

while (!pq.empty()) {
    vector<long long> room = pq.top();
    pq.pop();

    count[room[1]] = room[2];
}
```

After all meetings are processed, the heap contains exactly one entry for each room. This loop stores each room's meeting count in the `count` array.

Example:

```text
count = [3, 5, 2]
```

Room `0` held three meetings, room `1` held five, and room `2` held two.

## 9. Find the Room with the Most Meetings

```cpp
int ans = 0;

for (int i = 0; i < rooms; i++) {
    if (count[i] > count[ans]) {
        ans = i;
    }
}

return ans;
```

We begin with room `0`. We update the answer only if another room has a strictly greater count.

Why use `>` instead of `>=`?

If two rooms have the same maximum count, the problem requires the lowest room number. Using strict `>` preserves the earlier, smaller room index.

---

# Complete Dry Run — Example 1

Input:

```text
rooms = 2
meetings = [[0,10], [1,5], [2,7], [3,4]]
```

Initial heap:

```text
{0,0,0}
{0,1,0}
```

Each entry means:

```text
{available_time, room_number, meetings_count}
```

### Meeting 1: `[0,10]`

```text
start = 0
end = 10
duration = 10
```

Both rooms are free because both have ending time `0`.

Temporary vector:

```text
{0,0,0}
{0,1,0}
```

Sort by room number and select room `0`.

Updated room entry:

```text
{10,0,1}
```

Room `1` is restored unchanged.

Heap state:

```text
{0,1,0}
{10,0,1}
```

### Meeting 2: `[1,5]`

```text
start = 1
end = 5
duration = 4
```

Room `1` is free at time `0`; room `0` is busy until time `10`.

Select room `1`.

New entry:

```text
{5,1,1}
```

Heap:

```text
{5,1,1}
{10,0,1}
```

### Meeting 3: `[2,7]`

```text
start = 2
end = 7
duration = 5
```

Room `1` is busy until `5`, and room `0` is busy until `10`.

No room is free. The heap top is:

```text
{5,1,1}
```

The meeting is delayed until time `5`.

```text
newEnd = 5 + 5 = 10
```

Updated room entry:

```text
{10,1,2}
```

Heap:

```text
{10,0,1}
{10,1,2}
```

### Meeting 4: `[3,4]`

```text
start = 3
end = 4
duration = 1
```

Both rooms are busy until time `10`.

The heap compares room numbers because ending times tie. Room `0` is selected.

```text
newEnd = 10 + 1 = 11
```

Updated room entry:

```text
{11,0,2}
```

Heap:

```text
{10,1,2}
{11,0,2}
```

### Final Counts

```text
Room 0 = 2 meetings
Room 1 = 2 meetings
```

The counts tie, so the smaller room number wins.

**Answer: 0**

## Room Timeline

```text
TIME       0       1       2       3       5       10      11
           |-------|-------|-------|-------|-------|-------|

ROOM 0     [========= Meeting 1 =========]          [M4]
                                                   [10,11)

ROOM 1             [=== Meeting 2 ===]
                                            [Meeting 3]
                                            [5,10)
```

| Original meeting | Duration | Room | Actual interval |
|---|---:|---:|---|
| `[0,10]` | 10 | 0 | `[0,10)` |
| `[1,5]` | 4 | 1 | `[1,5)` |
| `[2,7]` | 5 | 1 | `[5,10)` |
| `[3,4]` | 1 | 0 | `[10,11)` |

---

## Complexity Analysis of Your Code

Let `m` be the number of meetings and `r` be the number of rooms.

| Operation | Complexity |
|---|---:|
| Sort meetings | `O(m log m)` |
| Extract up to `r` free rooms | `O(r log r)` per meeting |
| Sort temporary free-room vector | `O(r log r)` per meeting |
| Restore rooms to heap | `O(r log r)` per meeting |
| Final count scan | `O(r)` |

**Overall upper bound:** `O(m log m + m * r log r)`.

**Auxiliary space:** `O(r)` for the heap, temporary vector, and count array.

Because `r <= 100`, this approach can be workable, but repeatedly extracting and sorting all free rooms is avoidable overhead.

## Standard Optimization: Two Min-Heaps

The common optimized solution uses:

1. `availableRooms`: a min-heap containing free room numbers, ordered by room number.
2. `busyRooms`: a min-heap containing `{end_time, room_number}`, ordered by ending time and then room number.

Before processing each meeting, move every room with `end_time <= meeting_start` from `busyRooms` to `availableRooms`.

Then:
- If `availableRooms` is not empty, select its smallest room number.
- Otherwise, pop the earliest-ending room from `busyRooms` and delay the meeting.

This avoids collecting and sorting all free rooms for every meeting.

**Optimized complexity:**
- Time: `O(m log m + m log r)`.
- Auxiliary space: `O(r)`.

Both approaches implement the same scheduling rules. The two-heap version is the more efficient standard interview solution.
