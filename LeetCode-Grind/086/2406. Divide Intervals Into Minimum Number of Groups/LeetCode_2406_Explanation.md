# LeetCode 2406 — Divide Intervals Into Minimum Number of Groups

## Problem Goal

Divide all intervals into the minimum number of groups so that no two intervals in the same group intersect.

**Core observation:** The minimum number of groups equals the maximum number of intervals that overlap at the same point.

This file explains both of your C++ solutions:

1. Greedy + Min-Heap.
2. Sweep Line + Two Sorted Arrays.

---

# Approach 1 — Greedy + Min-Heap

## Complete Code 1

```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            if (!pq.empty() && nums[i][0] > pq.top())
            {
                pq.pop();
            }

            pq.push(nums[i][1]);
        }

        return pq.size();
    }
};
```

## 1. Sort the Intervals

```cpp
sort(nums.begin(), nums.end());
```

Intervals are sorted lexicographically: first by start, then by end when starts are equal.

Example:

```text
Before: [[5,10], [6,8], [1,5], [2,3], [1,10]]
After:  [[1,5], [1,10], [2,3], [5,10], [6,8]]
```

Processing by increasing start time lets us decide whether an existing group can be reused.

## 2. Create a Min-Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

The heap stores the ending times of intervals currently assigned to groups.

`pq.top()` gives the smallest ending time: the group that becomes free earliest.

## 3. Process Each Interval

```cpp
for (int i = 0; i < n; i++)
```

For each interval:
- `nums[i][0]` is its start.
- `nums[i][1]` is its end.

## 4. Reuse a Group When Possible

```cpp
if (!pq.empty() && nums[i][0] > pq.top())
{
    pq.pop();
}
```

If `currentStart > earliestEnd`, one existing group is free. Remove its old ending time because the current interval can reuse that group.

### Why strict `>`?

Intervals are inclusive:

```text
Previous: [1,5]
Current:  [5,8]
```

Both contain `5`, so they intersect. The group is reusable only if:

```text
previousEnd < currentStart
```

Therefore, the code correctly uses `nums[i][0] > pq.top()`. Using `>=` would be incorrect.

## 5. Insert the Current Ending Time

```cpp
pq.push(nums[i][1]);
```

Store the current interval's end in the heap. If no group was free, this increases the number of groups needed; otherwise, it records the new interval assigned to the reused group.

## 6. Return the Heap Size

```cpp
return pq.size();
```

The heap size at the end equals the maximum number of simultaneously overlapping intervals, which is the minimum number of groups needed.

The algorithm removes at most one ending time for each new interval. This is sufficient: the heap size tracks the maximum overlap reached so far, even if multiple old groups have become free.

## Dry Run — Example 1

Input:

```text
[[5,10], [6,8], [1,5], [2,3], [1,10]]
```

Sorted:

```text
[[1,5], [1,10], [2,3], [5,10], [6,8]]
```

Initially, `pq = []`.

| Current interval | Heap before | Action | Heap after |
|---|---|---|---|
| `[1,5]` | `[]` | Insert `5` | `[5]` |
| `[1,10]` | `[5]` | `1 > 5` false; insert `10` | `[5,10]` |
| `[2,3]` | `[5,10]` | `2 > 5` false; insert `3` | `[3,5,10]` |
| `[5,10]` | `[3,5,10]` | `5 > 3`; remove `3`, insert `10` | `[5,10,10]` |
| `[6,8]` | `[5,10,10]` | `6 > 5`; remove `5`, insert `8` | `[8,10,10]` |

Final heap size is `3`.

**Output: `3`**

---

# Approach 2 — Sweep Line + Two Sorted Arrays

## Complete Code 2 — Your Code

```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<int> s;
        vector<int> e;

        if (n == 1)
        {
            return 1;
        }

        for (int i = 0; i < n; i++)
        {
            s.push_back(nums[i][0]);
            e.push_back(nums[i][1]);
        }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int count = 0;
        int ans = INT_MIN;
        int i = 0;
        int j = 0;

        while (i < n && j < n)
        {
            if (s[i] <= e[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};
```

## Main Idea

Instead of storing complete intervals, separate their starting and ending points into two arrays:

```cpp
vector<int> s;
vector<int> e;
```

- `s` stores every interval's starting point.
- `e` stores every interval's ending point.

Sort both arrays independently. Then use two pointers to count how many intervals are active at the same time.

## 1. Store Start and End Points

```cpp
for (int i = 0; i < n; i++)
{
    s.push_back(nums[i][0]);
    e.push_back(nums[i][1]);
}
```

For example:

```text
nums = [[1,5], [1,10], [2,3], [5,10], [6,8]]

s = [1,1,2,5,6]
e = [5,10,3,10,8]
```

## 2. Sort Both Arrays

```cpp
sort(s.begin(), s.end());
sort(e.begin(), e.end());
```

After sorting:

```text
s = [1,1,2,5,6]
e = [3,5,8,10,10]
```

Now we can compare the next starting point with the next ending point.

## 3. Initialize the Variables

```cpp
int count = 0;
int ans = INT_MIN;
int i = 0;
int j = 0;
```

- `count`: number of currently active intervals.
- `ans`: maximum active interval count seen so far.
- `i`: pointer for the start array.
- `j`: pointer for the end array.

## 4. Process Starts and Ends

```cpp
while (i < n && j < n)
```

Continue while both arrays have unprocessed elements.

### Case 1: A new interval starts

```cpp
if (s[i] <= e[j])
{
    count++;
    i++;
}
```

If the next start is before or equal to the next end, a new interval starts before the earliest active interval finishes.

Because intervals are inclusive, equality also means overlap.

So:
- Increase `count`.
- Move the start pointer `i`.

### Case 2: An interval ends first

```cpp
else
{
    count--;
    j++;
}
```

If the next end is strictly smaller than the next start, an interval finishes before another begins.

So:
- Decrease `count`.
- Move the end pointer `j`.

### Why is the comparison `s[i] <= e[j]`?

Consider:

```text
Interval A = [1,5]
Interval B = [5,8]
```

At coordinate `5`, both intervals are active. Therefore, the start at `5` must be processed before the end at `5`.

That is why we use:

```cpp
s[i] <= e[j]
```

If we used `s[i] < e[j]`, intervals that touch at an endpoint would incorrectly be treated as non-overlapping.

## 5. Update the Maximum Overlap

```cpp
ans = max(ans, count);
```

After processing each start or end event, update the maximum number of active intervals.

That maximum is the minimum number of groups required.

## Dry Run — Example 1

Input:

```text
nums = [[5,10], [6,8], [1,5], [2,3], [1,10]]
```

After separating and sorting:

```text
s = [1,1,2,5,6]
e = [3,5,8,10,10]
```

Initially:

```text
count = 0
ans = INT_MIN
i = 0
j = 0
```

| Step | `s[i]` | `e[j]` | Decision | `count` | `ans` |
|---|---:|---:|---|---:|---:|
| 1 | 1 | 3 | Start: `1 <= 3` | 1 | 1 |
| 2 | 1 | 3 | Start: `1 <= 3` | 2 | 2 |
| 3 | 2 | 3 | Start: `2 <= 3` | 3 | 3 |
| 4 | 5 | 3 | End: `5 <= 3` is false | 2 | 3 |
| 5 | 5 | 5 | Start: `5 <= 5` | 3 | 3 |
| 6 | 6 | 5 | End: `6 <= 5` is false | 2 | 3 |
| 7 | 6 | 8 | Start: `6 <= 8` | 3 | 3 |
| 8 | No start left | 8 | End events remain | — | 3 |

The loop stops when `i == n`.

Maximum active intervals:

```text
ans = 3
```

**Output: `3`**

## Small Improvement to Your Code

Your special condition:

```cpp
if (n == 1)
{
    return 1;
}
```

is not necessary. The two-pointer logic also handles one interval correctly.

You can initialize:

```cpp
int ans = 0;
```

instead of `INT_MIN`, because the active count starts at zero and becomes positive when the first interval starts.

The resulting initialization can be:

```cpp
int count = 0;
int ans = 0;
int i = 0;
int j = 0;
```

The rest of your two-pointer logic can remain the same.

---

# Comparison of Both Approaches

| Feature | Approach 1: Min-Heap | Approach 2: Sweep Line |
|---|---|---|
| Main technique | Greedy + Min-Heap | Sorting + Two Pointers |
| Data structure | Priority queue | Two arrays |
| What is stored? | Group ending times | All starts and ends |
| Main operation | Reuse earliest-free group | Count active intervals |
| Time complexity | `O(n log n)` | `O(n log n)` |
| Space complexity | `O(n)` | `O(n)` |

## Which Approach Should You Prefer?

Both approaches are optimal in asymptotic time complexity.

- **Min-Heap:** Easier to understand when assigning intervals to groups and reusing a group as soon as it becomes free.
- **Sweep Line:** Useful when thinking about maximum simultaneous overlap and counting active intervals.

## Interview Points

1. Minimum groups equals maximum simultaneous overlap.
2. In the heap approach, sort intervals by starting time.
3. The heap stores ending times.
4. In the heap approach, use `currentStart > earliestEnd` because intervals are inclusive.
5. In the sweep-line approach, use `start <= end` so a new interval starting at an endpoint is counted before the ending interval is removed.
6. Both solutions take `O(n log n)` time and `O(n)` auxiliary space.

## Final Complexity

| Approach | Time | Space |
|---|---|---|
| Greedy + Min-Heap | `O(n log n)` | `O(n)` |
| Sweep Line + Two Arrays | `O(n log n)` | `O(n)` |
