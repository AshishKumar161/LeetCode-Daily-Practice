# LeetCode 35: Search Insert Position - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given a **strictly increasing sorted array** of distinct integers and a `target` value.
* We must return:
  1. The index of `target` if it already exists in `nums`.
  2. The insertion index where `target` should be placed to preserve sorted order if it does not exist.
* This problem is equivalent to finding the **Lower Bound** of `target`: the smallest index $i$ such that $\text{nums}[i] \ge \text{target}$.
* If all elements in `nums` are smaller than `target`, the target belongs at index $n$ (appended at the end).
* A standard binary search naturally solves this: when the binary search fails to find `target`, the `low` pointer always finishes at the first index where $\text{nums}[\text{low}] > \text{target}$, which is precisely the correct insertion index.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n -1 ;
        int mid = 0 ;

        while (low <= high)
        {
            mid = low + (high - low) / 2 ;

            if (nums[mid] == target)
            {
                return mid ;
            }

            if (nums[mid] < target)
            {
                low = mid +1 ;
            }

            if (nums[mid] > target)
            {
                high = mid -1 ;
            }
        }
        return low ;
    }
};
```

### Why Returning `low` Works:
1. **Target Found:** Whenever `nums[mid] == target`, the function returns `mid` immediately.
2. **Target Not Found:**
   - In binary search, whenever `nums[mid] < target`, we know `target` must lie strictly to the right, so we set `low = mid + 1`.
   - Whenever `nums[mid] > target`, `target` must lie to the left, so we set `high = mid - 1`.
   - When `low` crosses `high` (`low > high`), the search range $[low, high]$ becomes empty.
   - At this termination point, all elements to the left of `low` are strictly smaller than `target`, and all elements starting from `low` onward are strictly greater than `target`.
   - Therefore, `low` is the exact index where `target` must be inserted.

---

## 3. Comprehensive Dry Run

### Test Case 1: Target Exists (`nums = [1, 3, 5, 6]`, `target = 5`)
- $n = 4$, `low = 0`, `high = 3`

| Iteration | `low` | `high` | `mid = low + (high - low) / 2` | `nums[mid]` | Condition Met | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $3$ | $0 + (3 - 0) / 2 = 1$ | `nums[1] = 3` | $3 < 5$ | `low = mid + 1 = 2` |
| **2** | $2$ | $3$ | $2 + (3 - 2) / 2 = 2$ | `nums[2] = 5` | $5 == 5$ | **Return `mid = 2`** |

- **Output:** `2`

---

### Test Case 2: Target Does Not Exist - Insert Inside (`nums = [1, 3, 5, 6]`, `target = 2`)
- $n = 4$, `low = 0`, `high = 3`

| Iteration | `low` | `high` | `mid` | `nums[mid]` | Condition Met | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $3$ | $1$ | `nums[1] = 3` | $3 > 2$ | `high = mid - 1 = 0` |
| **2** | $0$ | $0$ | $0$ | `nums[0] = 1` | $1 < 2$ | `low = mid + 1 = 1` |

- Loop ends because `low (1) <= high (0)` is **false**.
- Returns `low = 1`.
- **Output:** `1` (Array would become `[1, 2, 3, 5, 6]`).

---

### Test Case 3: Target Larger Than All Elements (`nums = [1, 3, 5, 6]`, `target = 7`)
- $n = 4$, `low = 0`, `high = 3`

| Iteration | `low` | `high` | `mid` | `nums[mid]` | Condition Met | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $3$ | $1$ | `nums[1] = 3` | $3 < 7$ | `low = mid + 1 = 2` |
| **2** | $2$ | $3$ | $2$ | `nums[2] = 5` | $5 < 7$ | `low = mid + 1 = 3` |
| **3** | $3$ | $3$ | $3$ | `nums[3] = 6` | $6 < 7$ | `low = mid + 1 = 4` |

- Loop ends because `low (4) <= high (3)` is **false**.
- Returns `low = 4` (index $n$).
- **Output:** `4`.

---

## 4. Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\log n)$  
  The search interval is halved at each iteration. For an array of size $n$, the while loop executes at most $\lfloor \log_2 n \rfloor + 1$ times.
- **Space Complexity:** $\mathcal{O}(1)$  
  No extra memory or data structures are allocated. The algorithm operates in-place using only primitive pointers (`low`, `high`, `mid`, `n`).

---

## 5. Edge Cases Handled

1. **Insert at the Beginning (`target < nums[0]`):**
   - E.g., `nums = [2, 4, 6]`, `target = 1`.
   - `high` decrements repeatedly until `high = -1`. The loop breaks and returns `low = 0`.
2. **Insert at the End (`target > nums[n-1]`):**
   - E.g., `nums = [2, 4, 6]`, `target = 10`.
   - `low` increments repeatedly until `low = n`. The loop breaks and returns `n`.
3. **Single Element Array (`n = 1`):**
   - `nums = [3]`, `target = 3` $\rightarrow$ returns `0` immediately.
   - `nums = [3]`, `target = 1` $\rightarrow$ `high = -1`, returns `low = 0`.
   - `nums = [3]`, `target = 5` $\rightarrow$ `low = 1`, returns `low = 1`.