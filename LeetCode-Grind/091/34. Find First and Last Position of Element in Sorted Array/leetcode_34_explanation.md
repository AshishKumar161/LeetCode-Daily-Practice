# LeetCode 34: Find First and Last Position of Element in Sorted Array - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given a sorted array with duplicates (non-decreasing order) and a `target` integer.
* A standard binary search terminates as soon as any occurrence of `target` is found (`nums[mid] == target`). However, that occurrence could be in the middle of a sequence of identical elements.
* To locate both the starting index and the ending index within $\mathcal{O}(\log n)$ time, we run **two specialized binary searches**:
  1. **First Occurrence Search (Lower Boundary):**
     * When `nums[mid] == target`, record `ans[0] = mid`.
     * Continue searching to the left (`high = mid - 1`) because an earlier occurrence might exist.
  2. **Last Occurrence Search (Upper Boundary):**
     * When `nums[mid] == target`, record `ans[1] = mid`.
     * Continue searching to the right (`low = mid + 1`) because a later occurrence might exist.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        vector < int > ans  = { -1 , -1} ;

        while (low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if (nums[mid] ==  target) 
            {
                ans[0] = mid ;
                high = mid -1  ;
            }

            else if (nums[mid] < target )
            {
                low = mid +1 ;
            }

            else 
            {
                high = mid - 1 ;
            }
        }

        low = 0 ;
        high = n -1 ;

        while (low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if (nums[mid] ==  target) 
            {
                ans[1] = mid ;
                low = mid + 1  ;
            }

            else if (nums[mid] < target )
            {
                low = mid +1 ;
            }

            else 
            {
                high = mid - 1 ;
            }
        }

        return ans ;
    }
};
```

### Detailed Logic Breakdown:

1. **Initialization:**
   * `ans` starts as `{-1, -1}`. If `target` never matches any element, this default pair is returned automatically without extra checks.
2. **First Loop (Finding `ans[0]`):**
   * If `nums[mid] == target`: we found a valid index, store `ans[0] = mid`. Then shift the boundary `high = mid - 1` to throw away the right side and look for any occurrences earlier in the array.
   * Standard binary search conditions handle the `< target` and `> target` cases.
3. **Second Loop (Finding `ans[1]`):**
   * Reset `low = 0` and `high = n - 1`.
   * If `nums[mid] == target`: store `ans[1] = mid`. Then shift the boundary `low = mid + 1` to throw away the left side and look for any occurrences later in the array.

---

## 3. Comprehensive Dry Run

### Test Case: `nums = [5, 7, 7, 8, 8, 10]`, `target = 8`
* $n = 6$, `ans = [-1, -1]`

#### Pass 1: Find First Position (`ans[0]`)

| Step | `low` | `high` | `mid = low + (high - low) / 2` | `nums[mid]` | Evaluation | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $5$ | $0 + (5 - 0) / 2 = 2$ | `nums[2] = 7` | $7 < 8$ | `low = mid + 1 = 3` |
| **2** | $3$ | $5$ | $3 + (5 - 3) / 2 = 4$ | `nums[4] = 8` | $8 == 8$ (Match!) | `ans[0] = 4`, `high = mid - 1 = 3` |
| **3** | $3$ | $3$ | $3 + (3 - 3) / 2 = 3$ | `nums[3] = 8` | $8 == 8$ (Match!) | `ans[0] = 3`, `high = mid - 1 = 2` |

* Loop terminates because `low (3) <= high (2)` is false.
* **`ans[0]` is now locked at `3`**.

---

#### Pass 2: Find Last Position (`ans[1]`)
* Reset `low = 0`, `high = 5`

| Step | `low` | `high` | `mid = low + (high - low) / 2` | `nums[mid]` | Evaluation | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $5$ | $2$ | `nums[2] = 7` | $7 < 8$ | `low = mid + 1 = 3` |
| **2** | $3$ | $5$ | $4$ | `nums[4] = 8` | $8 == 8$ (Match!) | `ans[1] = 4`, `low = mid + 1 = 5` |
| **3** | $5$ | $5$ | $5$ | `nums[5] = 10` | $10 > 8$ | `high = mid - 1 = 4` |

* Loop terminates because `low (5) <= high (4)` is false.
* **`ans[1]` is now locked at `4`**.

---

#### Final Output:
* Returns `[3, 4]`.

---

## 4. Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\log n)$
  - First binary search runs in $\mathcal{O}(\log n)$ steps.
  - Second binary search runs in $\mathcal{O}(\log n)$ steps.
  - Total time: $\mathcal{O}(\log n) + \mathcal{O}(\log n) = \mathcal{O}(\log n)$, satisfying the problem requirement.
- **Space Complexity:** $\mathcal{O}(1)$
  - Output vector `ans` uses $\mathcal{O}(1)$ extra auxiliary memory (fixed size of 2).
  - Only a few primitive integer pointers (`low`, `high`, `mid`, `n`) are allocated.

---

## 5. Edge Cases Handled

1. **Empty Array (`nums = []`):**
   * $n = 0$, `high = -1`. The while loop condition `0 <= -1` is false immediately for both passes.
   * Directly returns initialized vector `[-1, -1]`.
2. **Target Not in Array (`nums = [5, 7, 7, 8, 8, 10]`, `target = 6`):**
   * In both passes, `nums[mid] == target` is never met.
   * `ans` remains unchanged and returns `[-1, -1]`.
3. **Single Element - Match (`nums = [8]`, `target = 8`):**
   * Pass 1: sets `ans[0] = 0`, `high = -1`.
   * Pass 2: sets `ans[1] = 0`, `low = 1`.
   * Returns `[0, 0]`.
4. **All Elements Identical to Target (`nums = [2, 2, 2, 2]`, `target = 2`):**
   * Pass 1 continually contracts `high` leftward until index `0`, setting `ans[0] = 0`.
   * Pass 2 continually contracts `low` rightward until index `3`, setting `ans[1] = 3`.
   * Returns `[0, 3]`.