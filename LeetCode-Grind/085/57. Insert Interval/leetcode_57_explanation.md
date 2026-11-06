# LeetCode 57 — Insert Interval: Explanation

## Approach: Greedy + Linear Traversal

Your solution uses the fact that the input intervals are already sorted by their starting points and do not overlap.

It processes three regions:
1. Copy intervals that end before the new interval starts.
2. Merge all intervals that overlap the new interval.
3. Copy all remaining intervals.

No sorting is needed.

## Your C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& arr) {
        int n = nums.size();
        int i = 0;
        vector<vector<int>> ans;

        while (i < n && nums[i][1] < arr[0])
        {
            ans.push_back({nums[i]});
            i++;
        }

        int start = arr[0];
        int end = arr[1];

        while (i < n && nums[i][0] <= end)
        {
            start = min(start, nums[i][0]);
            end = max(end, nums[i][1]);
            i++;
        }

        ans.push_back({start, end});

        while (i < n)
        {
            ans.push_back({nums[i]});
            i++;
        }

        return ans;
    }
};
```

Here, `nums` is the original interval list, `arr` is the new interval, `ans` stores the answer, and `i` is the traversal pointer.

---

## 1. Initialization

```cpp
int n = nums.size();
int i = 0;
vector<vector<int>> ans;
```

- `n` stores the number of existing intervals.
- `i` points to the current interval.
- `ans` stores the final result.

## 2. Copy Intervals Before the New Interval

```cpp
while (i < n && nums[i][1] < arr[0])
{
    ans.push_back({nums[i]});
    i++;
}
```

The condition means:

```text
current_interval_end < new_interval_start
```

If true, the current interval is completely before the new interval and cannot overlap it. Copy it directly and move to the next interval.

Example:

```text
nums = [[1,2], [3,5], [6,7]]
arr  = [4,8]
```

For `[1,2]`, `2 < 4` is true, so copy it:

```text
ans = [[1,2]]
```

For `[3,5]`, `5 < 4` is false. Stop because this interval may overlap the new interval.

### Why strict `<`?

The problem treats intervals sharing an endpoint as overlapping.

```text
[1,3] and [3,5]
```

They share point `3`, so they must merge into `[1,5]`. Therefore, an interval ending exactly at `arr[0]` must not be copied as a separate interval.

## 3. Initialize the Merge Boundaries

```cpp
int start = arr[0];
int end = arr[1];
```

Start with the new interval itself. For `[4,8]`:

```text
start = 4
end = 8
```

These boundaries expand as overlapping intervals are found.

## 4. Merge All Overlapping Intervals

```cpp
while (i < n && nums[i][0] <= end)
{
    start = min(start, nums[i][0]);
    end = max(end, nums[i][1]);
    i++;
}
```

The condition means:

```text
current_interval_start <= current_merged_end
```

If true, the current interval overlaps or touches the current merged range.

Update the boundaries:

```cpp
start = min(start, nums[i][0]);
end = max(end, nums[i][1]);
```

- `min()` keeps the smallest starting point.
- `max()` keeps the largest ending point.
- `i++` moves to the next interval.

### Example: Multiple Merges

```text
nums = [[1,2], [3,5], [6,7], [8,10], [12,16]]
arr  = [4,8]
```

After copying `[1,2]`, initialize:

```text
start = 4
end = 8
```

Process each candidate:

| Interval | Check | Updated range |
|---|---|---|
| `[3,5]` | `3 <= 8` | `[3,8]` |
| `[6,7]` | `6 <= 8` | `[3,8]` |
| `[8,10]` | `8 <= 8` | `[3,10]` |
| `[12,16]` | `12 <= 10` is false | Stop |

Notice `[8,10]` is merged because the intervals share endpoint `8`.

## 5. Add the Merged Interval

```cpp
ans.push_back({start, end});
```

After all overlapping intervals have been processed, add the combined interval.

For the example:

```text
ans = [[1,2], [3,10]]
```

## 6. Copy the Remaining Intervals

```cpp
while (i < n)
{
    ans.push_back({nums[i]});
    i++;
}
```

All remaining intervals start after the merged interval ends. Since the input was already sorted and non-overlapping, they can be copied directly.

For the example, `[12,16]` is appended:

```text
ans = [[1,2], [3,10], [12,16]]
```

## 7. Return the Result

```cpp
return ans;
```

The result is sorted and contains no overlapping intervals.

---

# Complete Dry Run — Example 2

Input:

```text
nums = [[1,2], [3,5], [6,7], [8,10], [12,16]]
arr  = [4,8]
```

Initial state:

```text
n = 5
i = 0
ans = []
```

### First loop: intervals before the new interval

For `[1,2]`:

```text
2 < 4 -> true
```

Copy it:

```text
ans = [[1,2]]
i = 1
```

For `[3,5]`:

```text
5 < 4 -> false
```

Stop the first loop.

### Initialize merge range

```text
start = 4
end = 8
```

### Second loop: merge overlaps

| Current interval | Condition | New range |
|---|---|---|
| `[3,5]` | `3 <= 8` | `[3,8]` |
| `[6,7]` | `6 <= 8` | `[3,8]` |
| `[8,10]` | `8 <= 8` | `[3,10]` |
| `[12,16]` | `12 <= 10` — false | Stop |

Now:

```text
start = 3
end = 10
i = 4
```

Append the merged interval:

```text
ans = [[1,2], [3,10]]
```

### Third loop: copy what remains

Copy `[12,16]`:

```text
ans = [[1,2], [3,10], [12,16]]
```

**Final output:**

```text
[[1,2], [3,10], [12,16]]
```

## Visual Understanding

Before:

```text
[1,2]  [3,5]  [6,7]  [8,10]  [12,16]
          \      |      /
New:       [4,8]
```

After:

```text
[1,2]  [3,10]  [12,16]
```

The first interval stays unchanged, the overlapping group becomes one interval, and the last interval stays unchanged.

---

# Complexity Analysis

Let `n` be the number of existing intervals.

### Time: O(n)

Each interval is visited at most once:
- First loop copies intervals before the new interval.
- Second loop merges overlapping intervals.
- Third loop copies the remaining intervals.

No sorting is performed.

**Time Complexity: `O(n)`**

### Space: O(n)

The result vector can contain up to `n + 1` intervals.

- Output space: `O(n)`.
- Extra variables apart from the output: `O(1)`.

**Auxiliary space excluding output: `O(1)`**

## Important Interview Observations

1. The input is already sorted. Do not sort it again.
2. The input intervals do not overlap, enabling a single traversal.
3. Use `<` in the first loop because sharing an endpoint means overlap.
4. Use `<=` in the merge loop for the same reason.
5. Use `min()` for the merged start and `max()` for the merged end.
6. The final loop copies untouched intervals.

**Final complexity: O(n) time and O(n) output space.**
