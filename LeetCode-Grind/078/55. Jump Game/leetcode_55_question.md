# LeetCode 55 — Jump Game

- **Difficulty:** Medium
- **Topics:** Array, Dynamic Programming, Greedy

## Problem Statement

You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return `true` if you can reach the last index, or `false` otherwise.

## Examples

### Example 1

**Input:** `nums = [2,3,1,1,4]`

**Output:** `true`

**Explanation:** Jump from index 0 to index 1, then jump from index 1 to the last index.

```text
Index:  0   1   2   3   4
Value: [2,  3,  1,  1,  4]
         └──> 1 ───────> 4
```

### Example 2

**Input:** `nums = [3,2,1,0,4]`

**Output:** `false`

**Explanation:** You can reach index 3, but its value is 0. You cannot move forward to index 4.

```text
Index:  0   1   2   3   4
Value: [3,  2,  1,  0,  4]
       reachable ───X   unreachable
```

## Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^5`

## Function Signature

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums);
};
```
