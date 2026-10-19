# Merge Intervals — C++ Solution and Explanation

**LeetCode:** [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)  
**Approach:** Sorting + Greedy

## C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (ans.empty() || nums[i][0] > ans.back()[1]) {
                ans.push_back(nums[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
        }

        return ans;
    }
};
```

## 1. Sort the Intervals

```cpp
sort(nums.begin(), nums.end());
```

This sorts intervals by start value (and then by end value when starts are equal). Sorting puts potentially overlapping intervals next to each other.

## 2. Result Vector

```cpp
vector<vector<int>> ans;
```

`ans` stores the merged intervals as the algorithm progresses.

## 3. Check for No Overlap

```cpp
if (ans.empty() || nums[i][0] > ans.back()[1])
```

- `ans.empty()` means there is no previous interval to compare with.
- `nums[i][0]` is the current interval's start.
- `ans.back()[1]` is the end of the last merged interval.
- If the current start is greater than the previous end, there is a gap, so add the interval separately.

The condition uses `>` rather than `>=`: `[1,4]` and `[4,5]` must merge into `[1,5]`.

## 4. Merge Overlapping Intervals

```cpp
ans.back()[1] = max(ans.back()[1], nums[i][1]);
```

If the intervals overlap, keep the last merged start and update its end to the larger end. `max` prevents the merged interval from shrinking when the current interval is contained inside it.

## Dry Run

Input: `[[1,3],[2,6],[8,10],[15,18]]`

| Current interval | Action | `ans` |
|---|---|---|
| `[1,3]` | Add first interval | `[[1,3]]` |
| `[2,6]` | Overlap; end becomes `max(3,6) = 6` | `[[1,6]]` |
| `[8,10]` | `8 > 6`, add separately | `[[1,6],[8,10]]` |
| `[15,18]` | `15 > 10`, add separately | `[[1,6],[8,10],[15,18]]` |

**Output:** `[[1,6],[8,10],[15,18]]`

## Complexity Analysis

Let `n` be the number of intervals.

- **Time:** `O(n log n)` for sorting plus `O(n)` for the single merge pass; overall `O(n log n)`.
- **Space:** `O(n)` for the result vector. Sorting may also use implementation-dependent stack space.

## Common Mistakes

- Not sorting before merging.
- Using `>=` instead of `>` in the no-overlap condition.
- Replacing the merged end with `nums[i][1]` instead of taking the maximum.
- Comparing against the current input interval instead of `ans.back()`.

## Key Takeaway

Sort first. If the next interval starts after the last merged interval ends, add it; otherwise, extend the last interval's end.
