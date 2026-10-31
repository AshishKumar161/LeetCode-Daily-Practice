# LeetCode 1235 — Maximum Profit in Job Scheduling: Explanation

## Approach: Sorting + Dynamic Programming + Binary Search

Your solution combines three techniques:

1. **Sorting:** Sort all jobs by start time.
2. **Dynamic Programming:** At each job, decide whether to take it or skip it.
3. **Binary Search:** If a job is selected, find the first later job that can start at or after its end time.

## Complete C++ Code

```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> SortedJob;

        for (int i = 0; i < n; i++) {
            SortedJob.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(SortedJob.begin(), SortedJob.end());

        vector<int> ans(n + 1, 0);
        vector<int> starts;

        for (int i = 0; i < n; i++) {
            starts.push_back(SortedJob[i][0]);
        }

        for (int i = n - 1; i >= 0; i--) {
            int curr_time = SortedJob[i][1];

            int next = lower_bound(
                starts.begin() + i + 1,
                starts.end(),
                curr_time
            ) - starts.begin();

            int take = SortedJob[i][2] + ans[next];
            int skip = ans[i + 1];

            ans[i] = max(take, skip);
        }

        return ans[0];
    }
};
```

## 1. Create the Job Records

```cpp
vector<vector<int>> SortedJob;

for (int i = 0; i < n; i++) {
    SortedJob.push_back({startTime[i], endTime[i], profit[i]});
}
```

Each job is stored together as:

```text
[start time, end time, profit]
```

For Example 1:

```text
Index   Start   End   Profit
  0       1      3      50
  1       2      4      10
  2       3      5      40
  3       3      6      70
```

Keeping the three values together ensures that sorting does not separate a job's start time, end time, and profit.

## 2. Sort the Jobs

```cpp
sort(SortedJob.begin(), SortedJob.end());
```

C++ sorts the inner vectors lexicographically: it compares start time first, then end time if start times are equal, then profit if needed.

The important result is that jobs are arranged in non-decreasing order of start time.

## 3. Understand the DP Array

```cpp
vector<int> ans(n + 1, 0);
```

`ans[i]` means:

> The maximum profit obtainable by considering sorted jobs from index `i` through index `n - 1`.

Therefore:

- `ans[0]`: maximum profit considering all jobs.
- `ans[1]`: maximum profit considering jobs from index 1 onward.
- `ans[n]`: zero, because no jobs remain.

We use `n + 1` elements so `ans[n]` is a valid base case.

## 4. Build the Start-Time Array

```cpp
vector<int> starts;

for (int i = 0; i < n; i++) {
    starts.push_back(SortedJob[i][0]);
}
```

For Example 1:

```text
starts = [1, 2, 3, 3]
```

This array is sorted, which is required for `lower_bound()`.

## 5. Process from Right to Left

```cpp
for (int i = n - 1; i >= 0; i--)
```

We calculate the DP values from the last job to the first.

Why? The current state uses `ans[next]` and `ans[i + 1]`. Both are to the right of `i`, so they must already be calculated.

## 6. Get the Current Job's End Time

```cpp
int curr_time = SortedJob[i][1];
```

`SortedJob[i][1]` is the current job's end time. The next selected job must start at or after this time.

For example, if the current job is `[1,3]`, the next job must have a start time `>= 3`.

## 7. Find the Next Compatible Job with `lower_bound()`

```cpp
int next = lower_bound(
    starts.begin() + i + 1,
    starts.end(),
    curr_time
) - starts.begin();
```

### What does `lower_bound()` do?

In a sorted range, `lower_bound()` returns an iterator to the **first element greater than or equal to the target**.

- Search begins at `starts.begin() + i + 1`.
- Search ends at `starts.end()`.
- Target is `curr_time`.

We begin at `i + 1` because we want a later job, not the current job.

### Example

```text
starts = [1, 2, 3, 3]
i = 0
curr_time = 3
```

Search begins at index `1`:

```text
Index:    0   1   2   3
starts:  [1,  2,  3,  3]
              ^^^^^^^^^
              Search range
```

The first value `>= 3` is at index `2`.

```cpp
next = 2;
```

So, after taking job 0, the next compatible job can be considered from index 2.

### Why subtract `starts.begin()`?

`lower_bound()` returns an iterator, not an integer index.

```cpp
lower_bound(...) - starts.begin()
```

converts the iterator position into an array index. If it points to `starts[2]`, the subtraction gives `2`.

If no compatible job exists, the iterator is `starts.end()`, so `next == n`. This is safe because `ans` has `n + 1` elements.

### Why `lower_bound()` instead of `upper_bound()`?

The problem allows a job to start exactly when the previous job ends.

For example:

```text
Current job: [1, 3]
Next job:       [3, 6]
```

Start time `3` is valid. `lower_bound()` finds the first value `>= 3`. `upper_bound()` would find the first value `> 3` and could skip a valid job.

## 8. Calculate the Take Choice

```cpp
int take = SortedJob[i][2] + ans[next];
```

If we take the current job:

- Earn its profit: `SortedJob[i][2]`.
- Add the best profit from the next compatible job onward: `ans[next]`.

```text
take = current job profit + best compatible future profit
```

## 9. Calculate the Skip Choice

```cpp
int skip = ans[i + 1];
```

If we skip the current job, we earn no profit from it and use the best result starting at the next index.

## 10. Store the Better Choice

```cpp
ans[i] = max(take, skip);
```

Choose whichever option gives more profit. After the loop, `ans[0]` contains the maximum profit for all jobs.

---

# Complete Dry Run — Example 1

Input:

```text
startTime = [1, 2, 3, 3]
endTime   = [3, 4, 5, 6]
profit    = [50, 10, 40, 70]
```

Sorted jobs:

```text
Index   Start   End   Profit
  0       1      3      50
  1       2      4      10
  2       3      5      40
  3       3      6      70
```

```text
starts = [1, 2, 3, 3]
ans    = [0, 0, 0, 0, 0]
```

We process indices `3`, `2`, `1`, and `0`.

### Iteration 1 — i = 3

Current job: `[3,6]`, profit `70`.

```text
curr_time = 6
```

Search begins at index 4. The range is empty, so:

```text
next = 4
take = 70 + ans[4] = 70
skip = ans[4] = 0
ans[3] = max(70, 0) = 70
```

DP array:

```text
ans = [0, 0, 0, 70, 0]
```

### Iteration 2 — i = 2

Current job: `[3,5]`, profit `40`.

```text
curr_time = 5
```

Search begins after index 2. There is no start time `>= 5`, so `next = 4`.

```text
take = 40 + ans[4] = 40
skip = ans[3] = 70
ans[2] = max(40, 70) = 70
```

DP array:

```text
ans = [0, 0, 70, 70, 0]
```

### Iteration 3 — i = 1

Current job: `[2,4]`, profit `10`.

```text
curr_time = 4
```

Search begins after index 1. There is no start time `>= 4`, so `next = 4`.

```text
take = 10 + ans[4] = 10
skip = ans[2] = 70
ans[1] = max(10, 70) = 70
```

DP array:

```text
ans = [0, 70, 70, 70, 0]
```

### Iteration 4 — i = 0

Current job: `[1,3]`, profit `50`.

```text
curr_time = 3
```

Search begins after index 0. The first start time `>= 3` is at index 2.

```text
next = 2
take = 50 + ans[2] = 50 + 70 = 120
skip = ans[1] = 70
ans[0] = max(120, 70) = 120
```

Final DP array:

```text
ans = [120, 70, 70, 70, 0]
```

**Final answer: `ans[0] = 120`.**

## Visualize the Selected Jobs

```text
Time:  1       2       3       4       5       6

Job 0: [===============]
       Start 1, End 3, Profit 50

Job 3:                 [=======================]
                       Start 3, End 6, Profit 70

Total profit = 50 + 70 = 120
```

Job 0 ends at time 3 and Job 3 starts at time 3, so they are compatible.

## DP Summary Table

| i | Current job | curr_time | next | take | skip | ans[i] |
|---:|---|---:|---:|---:|---:|---:|
| 3 | `[3,6,70]` | 6 | 4 | 70 | 0 | 70 |
| 2 | `[3,5,40]` | 5 | 4 | 40 | 70 | 70 |
| 1 | `[2,4,10]` | 4 | 4 | 10 | 70 | 70 |
| 0 | `[1,3,50]` | 3 | 2 | 120 | 70 | 120 |

## Complexity Analysis

Let `n` be the number of jobs.

| Operation | Time |
|---|---:|
| Build job records | `O(n)` |
| Sort jobs | `O(n log n)` |
| Build `starts` | `O(n)` |
| DP loop with binary search | `O(n log n)` |

**Overall Time Complexity: `O(n log n)`**

There are `n` iterations, and each iteration performs one `O(log n)` binary search.

**Space Complexity: `O(n)`**

The `SortedJob`, `starts`, and `ans` arrays each use linear space.

## Interview Notes

- `SortedJob[i]` stores `{start, end, profit}`.
- `starts` contains sorted start times for binary search.
- `ans[i]` is the best profit from index `i` onward.
- `take` selects the current job and jumps to `next`.
- `skip` ignores the current job and moves to `i + 1`.
- `lower_bound()` is needed because a next job may start exactly at the current job's end.

### Core DP Recurrence

```text
ans[i] = max(
    SortedJob[i][2] + ans[next],
    ans[i + 1]
)
```
