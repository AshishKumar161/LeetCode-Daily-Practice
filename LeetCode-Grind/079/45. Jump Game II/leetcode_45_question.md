# LeetCode 45 — Jump Game II

- **Difficulty:** Medium
- **Topics:** Array, Dynamic Programming, Greedy

## Problem Statement

You are given a **0-indexed** array of integers `nums` of length `n`. You are initially positioned at index `0`.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at index `i`, you can jump to any index `i + j` where:

- `0 <= j <= nums[i]`
- `i + j < n`

Return the **minimum number of jumps** required to reach index `n - 1`.

The test cases are generated such that you can reach index `n - 1`.

## Examples

### Example 1

**Input:**
```text
nums = [2,3,1,1,4]
```

**Output:**
```text
2
```

**Explanation:**

The minimum number of jumps to reach the last index is 2.

- Jump 1 step from index 0 to index 1.
- Then jump 3 steps from index 1 to index 4.

```text
Index:       0       1       2       3       4
Array:      [2]     [3]     [1]     [1]     [4]
             └──────>       (from index 0)
                     └──────────────────────> (from index 1)

Path: 0 -> 1 -> 4
Jumps: 2
```

### Example 2

**Input:**
```text
nums = [2,3,0,1,4]
```

**Output:**
```text
2
```

**Explanation:**

The minimum number of jumps to reach the last index is 2.

- Jump 1 step from index 0 to index 1.
- Then jump 3 steps from index 1 to index 4.

## Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- It is guaranteed that you can reach `nums[n - 1]`.

## Function Signature

```cpp
class Solution {
public:
    int jump(vector<int>& nums);
};
```

## What You Need to Return

Return the minimum number of jumps needed to reach the last index, not the maximum jump length and not the number of reachable positions.
