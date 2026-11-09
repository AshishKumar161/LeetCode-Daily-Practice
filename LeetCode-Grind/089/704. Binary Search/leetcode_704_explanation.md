# LeetCode 704: Binary Search - Detailed Explanation

## 1. Problem Understanding & Core Intuition

- We are given a **strictly increasing sorted array** of distinct integers and a `target` value.
- Linear search checks every element from index $0$ to $n-1$, running in $\mathcal{O}(n)$ time.
- Because the input array is already sorted, we can eliminate half of the search space in each step using **Binary Search**:
  - Compare `target` with the middle element `nums[mid]`.
  - If `nums[mid] == target`: we found the element, return `mid`.
  - If `nums[mid] > target`: because the array is sorted in ascending order, all elements to the right of `mid` are strictly greater than `nums[mid]` and thus greater than `target`. The target can only exist in the left half, so we narrow the search space by setting `high = mid - 1`.
  - If `nums[mid] < target`: all elements to the left of `mid` are smaller than `target`. We narrow the search space to the right half by setting `low = mid + 1`.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n - 1 ;

        while (low <= high )
        {
            int mid = low + (high - low ) / 2 ;

            if (target == nums[mid])
            {
                return mid ;
            }

            if (nums[mid] > target )
            {
                high = mid - 1 ;
            }
            else 
            {
                low = mid + 1 ;
            }
        }

        return -1 ;
    }
};
```

### Key Implementation Details:
1. **Loop Condition (`low <= high`):**
   - The `<=` is crucial because the search range is inclusive `[low, high]`. Even when `low == high`, there is still one candidate element to verify.
2. **Overflow-Safe Midpoint Calculation:**
   - Instead of writing `(low + high) / 2`, which can cause 32-bit signed integer overflow if `low + high > 2^{31} - 1`, we use:
     $$
     \text{mid} = \text{low} + \frac{\text{high} - \text{low}}{2}
     $$
   - This prevents integer overflow while correctly finding the midpoint.

---

## 3. Comprehensive Dry Run

### Test Case 1: `nums = [-1, 0, 3, 5, 9, 12]`, `target = 9`
- $n = 6$, `low = 0`, `high = 5`

| Iteration | `low` | `high` | `mid = low + (high - low) / 2` | `nums[mid]` | Condition Check | Next Boundary Update |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $5$ | $0 + (5 - 0) / 2 = 2$ | `nums[2] = 3` | $3 < 9$ (`nums[mid] < target`) | `low = mid + 1 = 3` |
| **2** | $3$ | $5$ | $3 + (5 - 3) / 2 = 4$ | `nums[4] = 9` | $9 == 9$ (`nums[mid] == target`) | **Return `mid = 4`** |

- **Output:** `4`

---

### Test Case 2: `nums = [-1, 0, 3, 5, 9, 12]`, `target = 2`
- $n = 6$, `low = 0`, `high = 5`

| Iteration | `low` | `high` | `mid` | `nums[mid]` | Condition Check | Next Boundary Update |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | $5$ | $2$ | `nums[2] = 3` | $3 > 2$ (`nums[mid] > target`) | `high = mid - 1 = 1` |
| **2** | $0$ | $1$ | $0$ | `nums[0] = -1` | $-1 < 2$ (`nums[mid] < target`) | `low = mid + 1 = 1` |
| **3** | $1$ | $1$ | $1$ | `nums[1] = 0` | $0 < 2$ (`nums[mid] < target`) | `low = mid + 1 = 2` |

- Loop terminates because `low (2) <= high (1)` is **false**.
- Element is not found in the array.
- **Output:** `-1`

---

## 4. Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\log n)$
  - In every iteration, the search window $[low, high]$ is divided in half:
    $$
    n \rightarrow \frac{n}{2} \rightarrow \frac{n}{4} \rightarrow \dots \rightarrow 1
    $$
  - The maximum number of comparisons before the window becomes empty is $\lfloor \log_2 n \rfloor + 1$.
- **Space Complexity:** $\mathcal{O}(1)$
  - Operates iteratively in-place using only three primitive integer pointers/variables (`low`, `high`, `mid`).

---

## 5. Edge Cases Handled

1. **Single Element - Match (`nums = [5]`, `target = 5`):**
   - `low = 0`, `high = 0`, `mid = 0`.
   - `nums[0] == 5` returns `0` on the first iteration.
2. **Single Element - No Match (`nums = [5]`, `target = -5`):**
   - `low = 0`, `high = 0`, `mid = 0`.
   - `nums[0] > -5` sets `high = -1`. Loop terminates and returns `-1`.
3. **Target Smaller Than Smallest Element (`target < nums[0]`):**
   - `high` repeatedly decrements until `high < 0`, correctly returning `-1`.
4. **Target Greater Than Largest Element (`target > nums[n-1]`):**
   - `low` repeatedly increments until `low >= n`, correctly returning `-1`.