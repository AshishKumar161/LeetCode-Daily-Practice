# LeetCode 540: Single Element in a Sorted Array - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given a sorted array where every integer appears in an adjacent pair **except for one single element**.
* Because the array is sorted and has pairs of size $2$ plus $1$ unique element, the total length $n$ is always **odd**.
* **Key Observation (Index Parity Shift):**
  * **Before the single element:** Every pair starts at an **even** index and ends at an **odd** index:
    $$
    (\text{even}, \text{odd}) \implies (0, 1),\; (2, 3),\; (4, 5), \dots
    $$
  * **At the single element:** The single element always sits at an **even** index because all pairs before it occupy an even number of slots ($2k$).
  * **After the single element:** The single element shifts all subsequent pairs by $1$ position, so every pair starts at an **odd** index and ends at an **even** index:
    $$
    (\text{odd}, \text{even}) \implies (3, 4),\; (5, 6),\; (7, 8), \dots
    $$

* By checking the parity of `mid` (`mid % 2 == 0` vs `mid % 2 == 1`) and comparing `nums[mid]` with its neighbor, we can determine in $\mathcal{O}(1)$ time whether `mid` lies before or after the single element and eliminate half the array!

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n - 1 ;

        while (low < high)
        {
            int mid = low + (high - low) / 2 ;

            if ( mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1] )
                {
                    low = mid + 2 ;
                }

                else
                {
                    high = mid ;
                }
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                {
                    low = mid + 1 ;
                }

                else
                {
                    high = mid ;
                }
            }
        }

        return nums[low] ;
    }
};
```

### Detailed Logic Breakdown:

1. **Loop Condition (`while (low < high)`):**
   * Because `high` is updated to `mid` (not `mid - 1`), we use strict `low < high`. When `low == high`, the search space converges onto the single unique element.
   * Since `low < high`, `mid` is always strictly less than `high` ($\text{mid} \le n - 2$), ensuring `mid + 1` is always within array bounds.
2. **Case 1: `mid` is Even (`mid % 2 == 0`):**
   * **`nums[mid] == nums[mid + 1]`:** The pair starts at an even index and ends at an odd index—normal alignment! The single element has not appeared yet and must lie strictly after `mid + 1`. Jump past the pair with `low = mid + 2`.
   * **`nums[mid] != nums[mid + 1]`:** Alignment is already broken (or `mid` itself is the single element). The single element is either `mid` or lies to its left. Narrow with `high = mid`.
3. **Case 2: `mid` is Odd (`else`):**
   * **`nums[mid] == nums[mid - 1]`:** The pair starts at an even index (`mid - 1`) and ends at an odd index (`mid`)—normal alignment! The single element must lie strictly after `mid`. Set `low = mid + 1`.
   * **`nums[mid] != nums[mid - 1]`:** Alignment is broken before `mid`. Since the single element cannot sit at an odd index (when `low` and `high` remain aligned, or even when `high` sits on an odd boundary before narrowing down), setting `high = mid` keeps the target inside `[low, high]`.
4. **Return Value:**
   * When `low == high`, return `nums[low]`.

---

## 3. Comprehensive Dry Run

### Test Case 1: `nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]` ($n = 9$)
* Initial state: `low = 0`, `high = 8`

| Iteration | `low` | `high` | `mid` | Parity of `mid` | Neighbor Check | Boundary Update | Remaining Subarray |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $8$ | $4$ | Even (`4 % 2 == 0`) | `nums[4] (3) == nums[5] (4)` is **False** | `high = mid = 4` | `[1, 1, 2, 3, 3]` |
| **2** | $0$ | $4$ | $2$ | Even (`2 % 2 == 0`) | `nums[2] (2) == nums[3] (3)` is **False** | `high = mid = 2` | `[1, 1, 2]` |
| **3** | $0$ | $2$ | $1$ | Odd (`1 % 2 == 1`) | `nums[1] (1) == nums[0] (1)` is **True** | `low = mid + 1 = 2` | `[2]` |

* Loop terminates because `low (2) < high (2)` is **false**.
* **Final Output:** `nums[2] = 2`.

---

### Test Case 2: `nums = [3, 3, 7, 7, 10, 11, 11]` ($n = 7$)
* Initial state: `low = 0`, `high = 6`

| Iteration | `low` | `high` | `mid` | Parity of `mid` | Neighbor Check | Boundary Update | Remaining Subarray |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $6$ | $3$ | Odd (`3 % 2 == 1`) | `nums[3] (7) == nums[2] (7)` is **True** | `low = mid + 1 = 4` | `[10, 11, 11]` |
| **2** | $4$ | $6$ | $5$ | Odd (`5 % 2 == 1`) | `nums[5] (11) == nums[4] (10)` is **False** | `high = mid = 5` | `[10, 11]` |
| **3** | $4$ | $5$ | $4$ | Even (`4 % 2 == 0`) | `nums[4] (10) == nums[5] (11)` is **False** | `high = mid = 4` | `[10]` |

* Loop terminates because `low (4) < high (4)` is **false**.
* **Final Output:** `nums[4] = 10`.

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(\log n)$
  * Each iteration reduces the search window `[low, high]` by roughly half, completing in at most $\lceil \log_2 n \rceil$ iterations.
* **Space Complexity:** $\mathcal{O}(1)$
  * Uses only four primitive integer variables (`n`, `low`, `high`, `mid`). No extra memory or recursion stack is used.

---

## 5. Edge Cases Handled

1. **Single Element Array (`nums = [5]`):**
   * $n = 1 \implies \text{low} = 0, \text{high} = 0$. `while (low < high)` does not run, returning `nums[0] = 5`.
2. **Unique Element at Index `0` (`nums = [1, 2, 2, 3, 3]`):**
   * `mid = 2` (even), `nums[2] != nums[3]` $\implies$ `high = 2`. Next `mid = 1` (odd), `nums[1] != nums[0]` $\implies$ `high = 1`. Next `mid = 0` (even), `nums[0] != nums[1]` $\implies$ `high = 0`. Returns `nums[0] = 1`.
3. **Unique Element at Last Index (`nums = [1, 1, 2, 2, 5]`):**
   * `mid = 2` (even), `nums[2] == nums[3]` $\implies$ `low = 4`. Loop ends since `low == high == 4`, returning `nums[4] = 5`.