# LeetCode 81: Search in Rotated Sorted Array II - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* This problem extends **LeetCode 33 (Search in Rotated Sorted Array)** by allowing **duplicate elements** in `nums`.
* In LeetCode 33 (distinct elements), comparing `nums[low] <= nums[mid]` always definitively told us whether the left half `[low, mid]` was sorted.
* **The Duplicate Ambiguity Problem:**
  * When duplicates exist, we can encounter the case where:
    $$\text{nums}[\text{low}] == \text{nums}[\text{mid}] == \text{nums}[\text{high}]$$
  * Consider `nums = [1, 0, 1, 1, 1]` vs `nums = [1, 1, 1, 0, 1]` with `target = 0`. In both cases, `low = 0, mid = 2, high = 4`, and `nums[low] = nums[mid] = nums[high] = 1`. We cannot tell which side contains the pivot drop-off!
* **How to Resolve the Ambiguity:**
  * Since we already verified `target != nums[mid]`, and `nums[low] == nums[mid] == nums[high]`, neither `nums[low]` nor `nums[high]` can be equal to `target`.
  * Therefore, it is completely safe to shrink the search boundaries from both ends (`low++` and `high--`) to eliminate the duplicate endpoints and continue binary searching.
  * Once `nums[low] == nums[mid] == nums[high]` no longer holds, at least one half (`[low, mid]` or `[mid, high]`) is guaranteed to be sorted, and standard rotated binary search applies.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 ; 
        int high = n - 1 ;

        while (low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if (target == nums[mid])
            {
                return true ;
            }

            if (nums[low] == nums[mid] && nums[mid] == nums[high]) 
            {
                low++ ;
                high-- ;
            }

            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1 ;
                }

                else 
                {
                    low = mid + 1 ;
                }
            }

            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1 ;
                }

                else 
                {
                    high = mid - 1 ;
                }
            }
        }

        return false ;
    }
};
```

### Detailed Logic Breakdown:
1. **Direct Target Check (`target == nums[mid]`):**
   * Checked first so that if `mid` lands on `target`, we immediately return `true`.
2. **Duplicate Boundary Reduction (`nums[low] == nums[mid] && nums[mid] == nums[high]`):**
   * Because `nums[mid] != target`, `nums[low]` and `nums[high]` are also guaranteed not to equal `target`.
   * Incrementing `low++` and decrementing `high--` safely discards both non-target duplicates without losing `target`.
3. **Left Half Sorted (`nums[low] <= nums[mid]`):**
   * Check if `target` lies within `[nums[low], nums[mid]]`. If yes, move `high = mid - 1`; otherwise, move `low = mid + 1`.
4. **Right Half Sorted (`else`):**
   * Check if `target` lies within `[nums[mid], nums[high]]`. If yes, move `low = mid + 1`; otherwise, move `high = mid - 1`.

---

## 3. Comprehensive Dry Run

### Test Case 1: `nums = [2, 5, 6, 0, 0, 1, 2]`, `target = 0`
* $n = 7$, `low = 0`, `high = 6`

| Iteration | `low` | `high` | `mid` | `nums[mid]` | Condition Check | Next Step |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| **1** | $0$ | $6$ | $3$ | `0` | `target == nums[3]` (`0 == 0`) | **Return `true` immediately** |

* **Final Output:** `true`.

---

### Test Case 2: Duplicate Endpoints (`nums = [1, 0, 1, 1, 1]`, `target = 0`)
* $n = 5$, `low = 0`, `high = 4`

| Iteration | `low` | `high` | `mid` | `nums[mid]` | Condition Met | Boundary Update |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| **1** | $0$ | $4$ | $2$ | `1` | `nums[0] == nums[2] == nums[4]` (`1 == 1 == 1`) | `low = 1`, `high = 3` |
| **2** | $1$ | $3$ | $2$ | `1` | `nums[1] <= nums[2]` (`0 <= 1`, left sorted), `0 <= 0 <= 1` is **True** | `high = mid - 1 = 1` |
| **3** | $1$ | $1$ | $1$ | `0` | `target == nums[1]` (`0 == 0`) | **Return `true`** |

* **Final Output:** `true`.

---

### Test Case 3: `nums = [2, 5, 6, 0, 0, 1, 2]`, `target = 3` (Not Present)
* $n = 7$, `low = 0`, `high = 6`

| Iteration | `low` | `high` | `mid` | `nums[mid]` | Condition Met | Boundary Update |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| **1** | $0$ | $6$ | $3$ | `0` | `nums[0] == 2`, `nums[3] == 0`, `nums[6] == 2` $\rightarrow$ Right `[0..2]` sorted; `0 <= 3 <= 2` is **False** | `high = mid - 1 = 2` |
| **2** | $0$ | $2$ | $1$ | `5` | Left `[2..5]` sorted; `2 <= 3 <= 5` is **True** | `high = mid - 1 = 0` |
| **3** | $0$ | $0$ | $0$ | `2` | Left `[2..2]` sorted; `2 <= 3 <= 2` is **False** | `low = mid + 1 = 1` |

* Loop terminates because `low (1) <= high (0)` is **false**.
* **Final Output:** `false`.

---

## 4. Complexity Analysis

* **Time Complexity:**
  * **Average / Best Case:** $\mathcal{O}(\log n)$ — When duplicates do not block halving, each iteration eliminates half of the remaining elements.
  * **Worst Case:** $\mathcal{O}(n)$ — When almost all elements are identical (e.g., `nums = [1, 1, 1, 1, 1, 0, 1]` and `target = 0`), `nums[low] == nums[mid] == nums[high]` triggers repeatedly, shrinking the search space by $2$ elements (`low++`, `high--`) per step for up to $n / 2$ iterations.
* **Space Complexity:** $\mathcal{O}(1)$
  * Uses only primitive integer variables (`n`, `low`, `high`, `mid`). No extra memory or recursion stack is allocated.

---

## 5. Edge Cases Handled

1. **All Elements Identical (`nums = [2, 2, 2, 2]`, `target = 3`):**
   * `low++` and `high--` shrink the window inward until `low > high`, safely returning `false`.
2. **Single Element Array (`nums = [1]`, `target = 1` or `0`):**
   * `low = 0, high = 0, mid = 0`. Returns `true` if `nums[0] == target`; otherwise `low++` and `high--` break the loop and return `false`.
3. **Target Is Equal to Duplicate Boundary Value (`nums = [1, 1, 3, 1]`, `target = 1`):**
   * If `mid` lands on `1`, `target == nums[mid]` returns `true` immediately before any shrinking occurs. If `mid` lands on `3`, `nums[low] == nums[mid]` is false (`1 != 3`), so normal sorted-half binary search locates `1`.