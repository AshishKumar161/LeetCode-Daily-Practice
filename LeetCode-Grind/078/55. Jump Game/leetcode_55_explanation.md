# LeetCode 55 — Jump Game: Explanation

## Approach: Greedy (Farthest Reachable Index)

The idea is to track the farthest index we can reach while traversing the array. We do not need to calculate the exact sequence of jumps.

### Meaning of `maxx`

```cpp
int maxx = 0;
```

`maxx` stores the farthest array index reachable from any position processed so far.

### Logic

For each index `i`:

1. Check whether the current index is reachable.
   ```cpp
   if (i > maxx) return false;
   ```
   If `i` is beyond `maxx`, there is no way to reach this index. Since jumps only move forward, later indices cannot be reached either.

2. Update the farthest reachable index.
   ```cpp
   maxx = max(maxx, nums[i] + i);
   ```
   From index `i`, the farthest jump reaches `i + nums[i]`. Keep the maximum of this value and the previous `maxx`.

3. If the loop completes without finding an unreachable index, return `true`.

## Complete C++ Code

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxx = 0;

        for (int i = 0; i < n; i++) {
            if (i > maxx) {
                return false;
            }

            maxx = max(maxx, nums[i] + i);
        }

        return true;
    }
};
```

## Dry Run — Example 1

Input: `nums = [2,3,1,1,4]`

Initially, `maxx = 0`.

| `i` | `nums[i]` | `i + nums[i]` | `maxx` after update |
|---:|---:|---:|---:|
| 0 | 2 | 2 | 2 |
| 1 | 3 | 4 | 4 |
| 2 | 1 | 3 | 4 |
| 3 | 1 | 4 | 4 |
| 4 | 4 | 8 | 8 |

Every index satisfies `i <= maxx`. The loop completes, so the answer is `true`.

## Dry Run — Example 2

Input: `nums = [3,2,1,0,4]`

| `i` | `nums[i]` | `i + nums[i]` | `maxx` after update |
|---:|---:|---:|---:|
| 0 | 3 | 3 | 3 |
| 1 | 2 | 3 | 3 |
| 2 | 1 | 3 | 3 |
| 3 | 0 | 3 | 3 |
| 4 | 4 | — | — |

At index `4`, the condition `4 > 3` is true. The algorithm returns `false` immediately.

## Why Does `i > maxx` Mean Failure?

`maxx` is the farthest position reachable from all positions visited so far. If the current index is greater than `maxx`, it lies outside the reachable region. No earlier index can jump to it, so it is impossible to reach the last index.

## Complexity Analysis

- **Time:** `O(n)` — one traversal; each iteration performs constant-time work.
- **Auxiliary space:** `O(1)` — only a few variables are used.

## Important Interview Notes

- This is a Greedy problem.
- `maxx` stores an index, not the number of jumps.
- A zero does not automatically mean failure; it matters whether it blocks all routes forward.
- Check reachability before updating `maxx`.
- If the loop finishes, the last index is reachable.
