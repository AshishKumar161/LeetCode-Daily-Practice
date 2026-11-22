# LeetCode 153: Find Minimum in Rotated Sorted Array - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given an array of **unique** integers originally sorted in ascending order and rotated between $1$ and $n$ times.
* Because of the rotation, the array consists of up to two sorted subarrays separated by a single "drop-off" point (the rotation pivot), where the **minimum element** resides:
  $$
  [\text{larger sorted segment} \;\mid\; \text{minimum element} \dots \text{smaller sorted segment}]
  $$
* **Key Observation (Comparing `nums[mid]` with `nums[high]`):**
  * At any step in our binary search window `[low, high]`, we compute `mid = low + (high - low) / 2` and compare `nums[mid]` against the right boundary `nums[high]`:
    1. **`nums[mid] > nums[high]`:**
       * Because `nums[mid]` is strictly greater than an element to its right (`nums[high]`), the rotation drop-off (and thus the minimum element) **must** lie strictly to the right of `mid`.
       * Furthermore, `nums[mid]` itself cannot be the minimum (since `nums[high]` is smaller), so we safely discard `mid` and set `low = mid + 1`.
    2. **`nums[mid] <= nums[high]`:**
       * The subarray `[mid, high]` is sorted in ascending order, which means the minimum element is either at `mid` itself or somewhere to its left.
       * Because `nums[mid]` could be the minimum element, we **cannot** discard `mid`; we narrow the right boundary to `high = mid`.

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n -1 ;

        while (low < high)
        {
            int mid = low + (high - low) / 2 ;

            if (nums[mid] > nums[high])
            {
                low = mid + 1 ;
            }

            else 
            {
                high = mid ;
            }
        }

        return nums[low] ;
    }
};
```

### Detailed Logic Breakdown:

1. **Strict Loop Condition (`while (low < high)`):**
   * Unlike standard exact-match binary search (`low <= high`), we use `low < high` because `high = mid` does not decrement `high` by $1$. If we used `low <= high`, when `low == high`, `mid` would equal `low`, causing `high = mid` to loop infinitely.
   * When `low == high`, the search space has narrowed down to a single candidate index, which is guaranteed to be the minimum element.

2. **Why `high = mid` (Not `mid - 1`):**
   * When `nums[mid] <= nums[high]`, `mid` itself might be the pivot minimum (e.g., `nums = [3, 1, 2]`, where `mid = 1` and `nums[mid] = 1`). Setting `high = mid` ensures we never skip past the answer.

3. **Return Value (`return nums[low];`):**
   * At termination (`low == high`), both `nums[low]` and `nums[high]` point directly to the minimum element.

## 3. Comprehensive Dry Run

### Test Case 1: `nums = [3, 4, 5, 1, 2]` ($n = 5$)

* Initial state: `low = 0`, `high = 4`

| Iteration | `low` | `high` | `mid = low + (high - low) / 2` | `nums[mid]` vs `nums[high]` | Condition Met | Boundary Update |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| **1** | $0$ | $4$ | $0 + (4 - 0) / 2 = 2$ | `5 > 2` | `nums[mid] > nums[high]` | `low = mid + 1 = 3` |
| **2** | $3$ | $4$ | $3 + (4 - 3) / 2 = 3$ | `1 > 2` (False) | `else` (`1 <= 2`) | `high = mid = 3` |

* Loop terminates because `low (3) < high (3)` is **false**.
* **Final Output:** `nums[3] = 1`.

---

### Test Case 2: `nums = [4, 5, 6, 7, 0, 1, 2]` ($n = 7$)

* Initial state: `low = 0`, `high = 6`

| Iteration | `low` | `high` | `mid` | `nums[mid]` vs `nums[high]` | Condition Met | Boundary Update |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| **1** | $0$ | $6$ | $3$ | `7 > 2` | `nums[mid] > nums[high]` | `low = mid + 1 = 4` |
| **2** | $4$ | $6$ | $5$ | `1 > 2` (False) | `else` (`1 <= 2`) | `high = mid = 5` |
| **3** | $4$ | $5$ | $4$ | `0 > 1` (False) | `else` (`0 <= 1`) | `high = mid = 4` |

* Loop terminates because `low (4) < high (4)` is **false**.
* **Final Output:** `nums[4] = 0`.

---

### Test Case 3: Unrotated Array `nums = [11, 13, 15, 17]` ($n = 4$)

* Initial state: `low = 0`, `high = 3`

| Iteration | `low` | `high` | `mid` | `nums[mid]` vs `nums[high]` | Condition Met | Boundary Update |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| **1** | $0$ | $3$ | $1$ | `13 > 17` (False) | `else` (`13 <= 17`) | `high = mid = 1` |
| **2** | $0$ | $1$ | $0$ | `11 > 13` (False) | `else` (`11 <= 13`) | `high = mid = 0` |

* Loop terminates because `low (0) < high (0)` is **false**.
* **Final Output:** `nums[0] = 11`.

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(\log n)$
  * On every iteration, the search interval `[low, high]` is cut roughly in half until `low == high`. This requires at most $\lceil \log_2 n \rceil$ comparisons.

* **Space Complexity:** $\mathcal{O}(1)$
  * Uses only four primitive integer variables (`n`, `low`, `high`, `mid`). No extra memory or recursion stack is used.

## 5. Edge Cases Handled

1. **Single Element Array (`nums = [5]`):**
   * $n = 1 \implies \text{low} = 0, \text{high} = 0$. The `while (low < high)` condition is immediately false, returning `nums[0] = 5`.

2. **Two Elements (`nums = [2, 1]` vs `nums = [1, 2]`):**
   * For `[2, 1]`: `mid = 0`, `nums[0] (2) > nums[1] (1)` $\implies$ `low = 1`. Loop ends and returns `nums[1] = 1`.
   * For `[1, 2]`: `mid = 0`, `nums[0] (1) <= nums[1] (2)` $\implies$ `high = 0`. Loop ends and returns `nums[0] = 1`.

3. **Array Rotated $n$ Times (Fully Sorted):**
   * Every step satisfies `nums[mid] <= nums[high]`, repeatedly halving `high = mid` down to index `0`, returning `nums[0]`.