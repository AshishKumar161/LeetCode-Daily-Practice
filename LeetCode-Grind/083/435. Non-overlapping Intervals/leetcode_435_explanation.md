# LeetCode 435 — Non-overlapping Intervals: Explanation

## Approach: Greedy + Sorting by End Point

Your solution sorts intervals by their ending value, then keeps an interval only when it starts at or after the ending point of the last kept interval.

**Greedy idea:** Choosing the interval that ends earliest leaves the maximum possible room for future intervals.

## Your C++ Code
```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1;
        int free_time = nums[0][1];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i][0] >= free_time) {
                count++;
                free_time = nums[i][1];
            }
        }

        return nums.size() - count;
    }
};
```

## 1. Sort by the Ending Value
```cpp
sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
});
```
`a[1]` and `b[1]` are the ending points. The comparator places the interval with the smaller ending point first.

Example:
```text
Before: [[1,2], [2,3], [3,4], [1,3]]
After:  [[1,2], [2,3], [1,3], [3,4]]
```
An interval that finishes earlier leaves more room for later intervals.

## 2. Initialize the Kept Count
```cpp
int count = 1;
```
The first interval is selected. `count` means the number of intervals **kept**, not removed.

## 3. Store the End of the Last Kept Interval
```cpp
int free_time = nums[0][1];
```
This stores the ending point of the most recently selected interval. For `[1,2]`, `free_time = 2`.

## 4. Traverse Remaining Intervals
```cpp
for (int i = 1; i < nums.size(); i++)
```
The first interval is already selected, so start at index `1`.

## 5. Check Whether the Current Interval Can Be Kept
```cpp
if (nums[i][0] >= free_time)
```
This checks:
```text
current_interval.start >= previous_interval.end
```
The `>=` is important. The problem says intervals that touch at a point are non-overlapping.

For example:
```text
[1,2] and [2,3]
2 >= 2  // true: both can be kept
```
If the current start is smaller than `free_time`, skip the interval because it overlaps the last kept interval.

## 6. Keep a Compatible Interval
```cpp
count++;
free_time = nums[i][1];
```
Increase the number kept and update the ending point to the newly selected interval's end. If an interval is skipped, do not update `free_time`.

## 7. Calculate Minimum Removals
```cpp
return nums.size() - count;
```
The problem asks how many intervals to remove:
```text
minimum removals = total intervals - kept intervals
```

---

# Dry Run — Example 1

Input:
```text
intervals = [[1,2], [2,3], [3,4], [1,3]]
```

After sorting by end:
```text
Index   Interval   Start   End
  0       [1,2]      1      2
  1       [2,3]      2      3
  2       [1,3]      1      3
  3       [3,4]      3      4
```

### Initialize
```text
count = 1
free_time = 2
Keep [1,2]
```

### Index 1: `[2,3]`
```text
2 >= 2  // true
```
Keep it:
```text
count = 2
free_time = 3
```

### Index 2: `[1,3]`
```text
1 >= 3  // false
```
Skip it. State remains `count = 2`, `free_time = 3`.

### Index 3: `[3,4]`
```text
3 >= 3  // true
```
Keep it:
```text
count = 3
free_time = 4
```

### Final Calculation
```text
total = 4
kept = 3
removals = 4 - 3 = 1
```
**Output: 1**

Visual:
```text
Sorted: [1,2]    [2,3]    [1,3]    [3,4]
         KEEP     KEEP    REMOVE    KEEP

Kept chain: [1,2] -> [2,3] -> [3,4]
Removed:    [1,3]
```

---

# Dry Run — Example 2

Input:
```text
intervals = [[1,2], [1,2], [1,2]]
```
Initialize `count = 1`, `free_time = 2`.

For each remaining `[1,2]`:
```text
1 >= 2  // false
```
Both are skipped.

```text
total = 3
kept = 1
removals = 3 - 1 = 2
```
**Output: 2**

# Dry Run — Example 3

Input:
```text
intervals = [[1,2], [2,3]]
```
Initialize `count = 1`, `free_time = 2`.

Check `[2,3]`:
```text
2 >= 2  // true
```
Keep it. Now `count = 2`.

```text
removals = 2 - 2 = 0
```
**Output: 0**

## Why Does Greedy Work?

Consider:
```text
A = [1,10]
B = [2,3]
C = [4,5]
D = [6,7]
```
Keeping `A` prevents us from keeping `B`, `C`, and `D`. Choosing the earliest-ending interval instead lets us keep:
```text
[2,3] -> [4,5] -> [6,7]
```
This maximizes the number kept. Since `removals = total - kept`, it also minimizes removals.

## Complexity Analysis

Let `n` be the number of intervals.

| Operation | Complexity |
|---|---:|
| Sorting | `O(n log n)` |
| Traversal | `O(n)` |
| Overall time | `O(n log n)` |

**Time:** `O(n log n)`  
**Auxiliary space:** `O(1)` for the greedy scan, excluding sorting's internal stack space (typically `O(log n)`).

## Interview Notes
- Sort by ending value.
- Keep the interval that ends earliest.
- Use `current_start >= previous_end`; equality is allowed.
- Update `free_time` only when an interval is kept.
- Return `n - count`, because the question asks for removals.

## Cleaner Version
```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int kept = 1;
        int free_time = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= free_time) {
                kept++;
                free_time = intervals[i][1];
            }
        }

        return intervals.size() - kept;
    }
};
```
