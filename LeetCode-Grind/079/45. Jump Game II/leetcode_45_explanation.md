# LeetCode 45 — Jump Game II: Explanation

## Approach: Greedy (BFS-Level / Range Expansion)

Your code uses a Greedy strategy that works like **Breadth-First Search (BFS) without explicitly using a queue**.

The important idea is to process all positions that can be reached using the current number of jumps. While processing that range, calculate how far the next jump can take us.

### Complete C++ Code

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jump = 0;
        int curr_End = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, nums[i] + i);

            if (curr_End == i) {
                jump++;
                curr_End = farthest;
            }
        }

        return jump;
    }
};
```

## Meaning of the Three Variables

### 1. `jump`

```cpp
int jump = 0;
```

Stores the number of jumps made so far.

We increase it when we finish exploring the current reachable range and must move to the next range.

### 2. `curr_End`

```cpp
int curr_End = 0;
```

Stores the last index that can be reached using the current number of jumps.

When the loop reaches `i == curr_End`, we have finished checking every index in the current range. We must now count another jump and update the boundary.

### 3. `farthest`

```cpp
int farthest = 0;
```

Stores the farthest index reachable from any index examined in the current range.

At index `i`, the farthest position reachable directly from that index is:

```cpp
nums[i] + i
```

We keep the maximum:

```cpp
farthest = max(farthest, nums[i] + i);
```

## Why Does the Loop Stop at `n - 1`?

```cpp
for (int i = 0; i < n - 1; i++)
```

We do not need to jump from the last index. Reaching it is the goal, so processing it would only risk counting an unnecessary jump.

## Why Do We Check `curr_End == i`?

```cpp
if (curr_End == i)
{
    jump++;
    curr_End = farthest;
}
```

This means we have reached the end of the range covered by the current number of jumps.

- Increment `jump` because we need one more jump to move into the next range.
- Set `curr_End = farthest` to make the farthest position found so far the new range boundary.

This is the central greedy decision in the algorithm.

## Dry Run — Example 1

**Input:**

```text
nums = [2, 3, 1, 1, 4]
```

Initial values:

```text
jump = 0
curr_End = 0
farthest = 0
```

| `i` | `nums[i]` | `i + nums[i]` | `farthest` | Is `i == curr_End`? | Action |
|---:|---:|---:|---:|---|---|
| 0 | 2 | 2 | 2 | Yes | `jump = 1`, `curr_End = 2` |
| 1 | 3 | 4 | 4 | No | Continue scanning current range |
| 2 | 1 | 3 | 4 | Yes | `jump = 2`, `curr_End = 4` |
| 3 | 1 | 4 | 4 | No | Continue; loop ends |

Final answer:

```text
jump = 2
```

### Visualize the Ranges

```text
Array:       [2, 3, 1, 1, 4]
Index:        0  1  2  3  4

Before first jump:
              [0]
               |
               | Explore index 0
               v
Reachable range after 1 jump:
              [0, 1, 2]
                  |
                  | Explore indices 1 and 2
                  | farthest reachable index = 4
                  v
Reachable range after 2 jumps:
              [0, 1, 2, 3, 4]
                              ^
                         Destination
```

The first jump gives us a range ending at index 2. While exploring that range, index 1 tells us that index 4 can be reached. Therefore, the second jump reaches the destination.

## Dry Run — Example 2

**Input:**

```text
nums = [2, 3, 0, 1, 4]
```

| `i` | `nums[i]` | `i + nums[i]` | `farthest` | Boundary reached? | Action |
|---:|---:|---:|---:|---|---|
| 0 | 2 | 2 | 2 | Yes | `jump = 1`, `curr_End = 2` |
| 1 | 3 | 4 | 4 | No | Continue |
| 2 | 0 | 2 | 4 | Yes | `jump = 2`, `curr_End = 4` |
| 3 | 1 | 4 | 4 | No | Loop ends |

Answer:

```text
2
```

Even though index 2 contains zero, index 1 already expanded `farthest` to index 4. So the destination remains reachable in two jumps.

## Why Is This Similar to BFS?

In BFS, we explore nodes level by level:

- Level 0: positions reachable with 0 jumps.
- Level 1: positions reachable with 1 jump.
- Level 2: positions reachable with 2 jumps.

This solution represents each BFS level as a continuous index range.

- `curr_End` marks the end of the current level.
- `farthest` calculates the end of the next level.
- `jump` counts the levels, which correspond to jumps.

We do not need a queue because the reachable positions are represented by ranges.

## Complexity Analysis

Let `n` be the number of elements in `nums`.

- **Time Complexity: `O(n)`** — the array is traversed once. Each iteration performs constant-time operations.
- **Auxiliary Space Complexity: `O(1)`** — only three additional variables are used.

## Important Interview Points

1. This is a Greedy problem.
2. It can be understood as BFS-level traversal with range boundaries.
3. `farthest` is the farthest index discovered while exploring the current range.
4. `curr_End` is the boundary of the current jump range.
5. `jump` counts the minimum number of jumps.
6. We stop at `n - 1` because no jump is needed after reaching the destination.
7. The problem guarantees that the last index is reachable.

## Common Mistakes

- Confusing `farthest` with `curr_End`: one is the next boundary being discovered; the other is the current boundary.
- Incrementing `jump` at every index instead of only when `i == curr_End`.
- Iterating through the last index and accidentally counting an unnecessary jump.
- Updating `curr_End` to `i` instead of to `farthest`.
