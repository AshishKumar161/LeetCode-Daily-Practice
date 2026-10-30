# 1834. Single-Threaded CPU

**LeetCode:** [1834. Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/)  
**Difficulty:** Medium · **Topics:** Array, Sorting, Heap (Priority Queue)

## Problem Statement

You are given `n` tasks labelled from `0` to `n - 1`. Each task is represented by two integers:

- `tasks[i][0]`: the **enqueue time**, when task `i` becomes available.
- `tasks[i][1]`: the **processing time**, the time required to complete task `i`.

A single-threaded CPU can process at most one task at a time and follows these rules:

1. If the CPU is idle and no task is available, it remains idle until a task arrives.
2. If the CPU is idle and one or more tasks are available, it chooses the task with the shortest processing time.
3. If multiple available tasks have the same processing time, it chooses the task with the smallest original index.
4. Once a task starts, the CPU completes it without interruption.
5. The CPU can start another task immediately after finishing the current one.

Return the order in which the CPU processes the tasks, represented by their original indices.

## Examples

### Example 1

**Input:**
```text
tasks = [[1,2],[2,4],[3,2],[4,1]]
```

**Output:**
```text
[0,2,3,1]
```

**Explanation:**

- At time `1`, task `0` is available. The CPU runs it for `2` units and finishes at time `3`.
- At time `3`, tasks `1` and `2` are available. Task `2` has the shorter processing time (`2` rather than `4`), so it runs next and finishes at time `5`.
- At time `5`, task `3` is available and task `1` is waiting. Task `3` has the shorter processing time, so it runs next and finishes at time `6`.
- Finally, task `1` runs.

### Example 2

**Input:**
```text
tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
```

**Output:**
```text
[4,3,2,0,1]
```

**Explanation:** All tasks are available at time `7`. The CPU chooses them by increasing processing time: task `4`, task `3`, task `2`, task `0`, and task `1`.

## Visual Representation

Example 1:

```text
Task index        0       1       2       3
Enqueue time      1       2       3       4
Processing time   2       4       2       1

Time 1:  Task 0 is available. Run task 0.
Time 3:  Tasks 1 and 2 are available. Run task 2 (shorter task).
Time 5:  Tasks 1 and 3 are available. Run task 3 (shorter task).
Time 6:  Run the remaining task 1.

CPU order: 0 -> 2 -> 3 -> 1
```

## Constraints

- `1 <= tasks.length <= 10^5`
- `1 <= enqueueTime_i, processingTime_i <= 10^9`

## Function Signature

```cpp
vector<int> getOrder(vector<vector<int>>& tasks);
```

**Important:** Return original task indices. Do not return the positions of tasks in the sorted array.

See `leetcode_1834_explanation.md` for detailed explanations of both implementations:
1. Sorting + C++ `priority_queue`.
2. Sorting + manually implemented min-heap using packed `long long` values.
