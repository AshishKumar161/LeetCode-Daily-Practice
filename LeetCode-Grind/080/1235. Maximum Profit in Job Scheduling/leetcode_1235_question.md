# LeetCode 1235 — Maximum Profit in Job Scheduling

**Difficulty:** Hard  
**Topics:** Array, Sorting, Binary Search, Dynamic Programming

## Problem Statement

We have `n` jobs. Every job is scheduled from `startTime[i]` to `endTime[i]`, and completing it earns `profit[i]`.

Given three integer arrays `startTime`, `endTime`, and `profit`, return the maximum total profit obtainable by selecting jobs such that no two selected jobs overlap.

If one job ends at time `X`, another job may start at time `X`. Thus, two jobs are compatible when:

```text
next job's start time >= current job's end time
```

## Examples

### Example 1

**Input**
```text
startTime = [1,2,3,3]
endTime   = [3,4,5,6]
profit    = [50,10,40,70]
```

**Output**
```text
120
```

**Explanation**

Choose Job 0 `[1,3]` with profit `50`, then Job 3 `[3,6]` with profit `70`.

```text
Job 0: [1 -------- 3]                 profit = 50
Job 3:             [3 -------------- 6] profit = 70

Total = 50 + 70 = 120
```

The jobs are compatible because the first ends exactly when the second starts.

### Example 2

**Input**
```text
startTime = [1,2,3,4,6]
endTime   = [3,5,10,6,9]
profit    = [20,20,100,70,60]
```

**Output**
```text
150
```

**Explanation:** Choose `[1,3]`, `[4,6]`, and `[6,9]`. Total profit is `20 + 70 + 60 = 150`.

### Example 3

**Input**
```text
startTime = [1,1,1]
endTime   = [2,3,4]
profit    = [5,6,4]
```

**Output**
```text
6
```

**Explanation:** All jobs overlap because they start at time `1`. Choose the job with profit `6`.

## Constraints

- `1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4`
- `1 <= startTime[i] < endTime[i] <= 10^9`
- `1 <= profit[i] <= 10^4`

## Function Signature

```cpp
int jobScheduling(vector<int>& startTime,
                  vector<int>& endTime,
                  vector<int>& profit);
```

**Goal:** Maximize total profit without scheduling overlapping jobs.
