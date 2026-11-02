# LeetCode 646 — Maximum Length of Pair Chain: Explanation

## Approach: Greedy + Sorting by End Point

Your code sorts pairs by their second element (ending value), then selects a pair only when its starting value is strictly greater than the ending value of the previously selected pair.

**Greedy idea:** Choosing the pair that ends earliest leaves as much room as possible for future pairs.

## Your C++ Code

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int curr_time = 1;
        int free_time = nums[0][1];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i][0] > free_time) {
                curr_time++;
                free_time = nums[i][1];
            }
        }

        return curr_time;
    }
};
```

## 1. Sort by the Second Element

```cpp
sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
});
```

`a[1]` and `b[1]` are the ending values of the two pairs. The comparator puts the pair with the smaller ending value first.

Example:

```text
Before: [[1,2], [7,8], [4,5]]
After:  [[1,2], [4,5], [7,8]]
```

Why sort by ending value? A pair that ends earlier leaves more room to select later pairs.

## 2. Initialize the Chain Count

```cpp
int curr_time = 1;
```

The first pair is always selected, so the chain length starts at `1`. `curr_time` is a count, not a clock. A clearer name is `count`.

## 3. Store the End of the Selected Pair

```cpp
int free_time = nums[0][1];
```

This stores the ending value of the last selected pair.

For the first pair `[1,2]`, `free_time = 2`.

## 4. Traverse the Remaining Pairs

```cpp
for (int i = 1; i < nums.size(); i++)
```

The first pair is already selected, so start from index `1`.

## 5. Check Whether the Current Pair Can Follow

```cpp
if (nums[i][0] > free_time)
```

The problem's rule is:

```text
previous pair end < current pair start
```

In your code, `free_time` is the previous end and `nums[i][0]` is the current start.

The comparison must be `>` because equality is not allowed. For example, `[1,2]` cannot be followed by `[2,3]`.

## 6. Select a Compatible Pair

```cpp
curr_time++;
free_time = nums[i][1];
```

If the condition is true:
- Increase the chain length.
- Update `free_time` to the end of the newly selected pair.

If the condition is false, skip the pair and do not change `free_time`.

## 7. Return the Answer

```cpp
return curr_time;
```

Return the number of selected pairs.

---

# Complete Dry Run — Example 1

Input:

```text
pairs = [[1,2], [2,3], [3,4]]
```

After sorting:

```text
Index    Pair    Start    End
  0     [1,2]      1       2
  1     [2,3]      2       3
  2     [3,4]      3       4
```

### Initialize

```text
curr_time = 1
free_time = 2
Selected: [1,2]
```

### Check Index 1: `[2,3]`

```text
nums[1][0] > free_time
2 > 2
false
```

Skip `[2,3]`. State remains:

```text
curr_time = 1
free_time = 2
```

### Check Index 2: `[3,4]`

```text
3 > 2
true
```

Select `[3,4]`:

```text
curr_time = 2
free_time = 4
```

Final chain:

```text
[1,2] -> [3,4]
```

**Output: 2**

## Visual Dry Run

```text
Sorted pairs:

[1,2]       [2,3]       [3,4]
 SELECT        SKIP       SELECT

free_time:
   2            2           4

Chain: [1,2] ----------------> [3,4]
```

---

# Complete Dry Run — Example 2

Input:

```text
pairs = [[1,2], [7,8], [4,5]]
```

After sorting:

```text
[[1,2], [4,5], [7,8]]
```

Initialize:

```text
count = 1
free_time = 2
```

Check `[4,5]`:

```text
4 > 2  // true
```

Select it:

```text
count = 2
free_time = 5
```

Check `[7,8]`:

```text
7 > 5  // true
```

Select it:

```text
count = 3
free_time = 8
```

Final chain:

```text
[1,2] -> [4,5] -> [7,8]
```

**Output: 3**

## Why Does Greedy Work?

Consider:

```text
A = [1,10]
B = [2,3]
C = [4,5]
D = [6,7]
```

Selecting A first gives a chain of length `1`. Selecting the pair with the earliest end first gives:

```text
[2,3] -> [4,5] -> [6,7]
```

This gives length `3`. An early finishing pair leaves more room for future pairs.

## Complexity Analysis

Let `n` be the number of pairs.

| Operation | Complexity |
|---|---:|
| Sorting | `O(n log n)` |
| Traversal | `O(n)` |
| Overall time | `O(n log n)` |

**Time:** `O(n log n)`  
**Auxiliary space:** `O(1)` for the greedy scan, excluding sorting implementation details (typically `O(log n)` stack space for sorting).

## Interview Notes

- Sort by the ending value, not the starting value.
- Select the first pair.
- Check `current_start > previous_end`.
- Equality is not allowed.
- Update the previous ending value only when a pair is selected.
- `curr_time` is a count, not actual time.

## Cleaner Version

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 1;
        int free_time = pairs[0][1];

        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > free_time) {
                count++;
                free_time = pairs[i][1];
            }
        }

        return count;
    }
};
```

This version only improves naming and comparator const-correctness; the greedy logic is the same.
