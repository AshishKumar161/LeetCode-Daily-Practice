# LeetCode 33: Search in Rotated Sorted Array - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given a strictly increasing array of distinct integers that has been rotated at some pivot index (or not rotated at all).

* Unlike a completely sorted array, we cannot blindly compare `target` with `nums[mid]` alone to decide whether to go left or right, because one half of the array wraps around the pivot drop-off.

* **Crucial Observation (At Least One Half Is Always Sorted):**

  * When we divide the search space `[low, high]` at `mid`, **at least one of the two halves** (`[low, mid]` or `[mid, high]`) is guaranteed to be strictly sorted in ascending order:

    1. **Left Half Sorted (`nums[low] <= nums[mid]`):**

       * Since `[low, mid]` is cleanly sorted, we can check if `target` lies within its endpoints: `nums[low] <= target && target <= nums[mid]`.

       * If yes, `target` must be in the left half $\rightarrow$ eliminate the right half (`high = mid - 1`).

       * Otherwise, `target` must be in the right half $\rightarrow$ eliminate the left half (`low = mid + 1`).

    2. **Right Half Sorted (`nums[low] > nums[mid]`):**

       * If the left half contains the rotation pivot, then `[mid, high]` is guaranteed to be cleanly sorted.

       * Check if `target` lies within the right half's endpoints: `nums[mid] <= target && target <= nums[high]`.

       * If yes, search the right half (`low = mid + 1`).

       * Otherwise, search the left half (`high = mid - 1`).

* This guarantees we discard half of the search space on every step, preserving $\mathcal{O}(\log n)$ runtime.

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ; 

        int low = 0 ;
        int high = n - 1 ;

        while ( low <= high )
        {
            int mid = low + (high - low) / 2 ;
            if (target == nums[mid])
            {
                return mid ;
            }

            if (nums[low] <= nums[mid])
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

        return -1 ;
     }
};
```

### Key Implementation Details:

1. **Immediate Match Check (`target == nums[mid]`):**

   * Checked first so that if `mid` lands directly on `target`, we return `mid` immediately.

2. **Why `nums[low] <= nums[mid]` Uses `<=`:**

   * When the search window narrows down to $2$ elements (e.g., `low = 4, high = 5`), integer division produces `mid = low` (`mid = 4`).

   * Using `<=` (`nums[4] <= nums[4]`) properly identifies the single-element left half `[low, mid]` as sorted, checks `nums[low] <= target <= nums[mid]`, and moves `low = mid + 1` to examine index `5` on the next iteration.

## 3. Comprehensive Dry Run

### Test Case 1: `nums = [4, 5, 6, 7, 0, 1, 2]`, `target = 0`

* $n = 7$, `low = 0`, `high = 6`

| Iteration | `low` | `high` | `mid` | `nums[mid]` | Sorted Half Check (`nums[low] <= nums[mid]`) | Range Check & Next Step |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| **1** | $0$ | $6$ | $3$ | `7` | `4 <= 7` (**True** $\rightarrow$ Left `[4..7]` sorted) | Is `4 <= 0 <= 7`? **False** $\rightarrow$ `low = mid + 1 = 4` |
| **2** | $4$ | $6$ | $5$ | `1` | `0 <= 1` (**True** $\rightarrow$ Left `[0..1]` sorted) | Is `0 <= 0 <= 1`? **True** $\rightarrow$ `high = mid - 1 = 4` |
| **3** | $4$ | $4$ | $4$ | `0` | `target == nums[4]` (**Match!**) | **Return `mid = 4`** |

* **Final Output:** `4`.

### Test Case 2: `nums = [4, 5, 6, 7, 0, 1, 2]`, `target = 3` (Not Present)

* $n = 7$, `low = 0`, `high = 6`

| Iteration | `low` | `high` | `mid` | `nums[mid]` | Sorted Half Check (`nums[low] <= nums[mid]`) | Range Check & Next Step |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| **1** | $0$ | $6$ | $3$ | `7` | `4 <= 7` (**True** $\rightarrow$ Left `[4..7]` sorted) | Is `4 <= 3 <= 7`? **False** $\rightarrow$ `low = mid + 1 = 4` |
| **2** | $4$ | $6$ | $5$ | `1` | `0 <= 1` (**True** $\rightarrow$ Left `[0..1]` sorted) | Is `0 <= 3 <= 1`? **False** $\rightarrow$ `low = mid + 1 = 6` |
| **3** | $6$ | $6$ | $6$ | `2` | `2 <= 2` (**True** $\rightarrow$ Left `[2..2]` sorted) | Is `2 <= 3 <= 2`? **False** $\rightarrow$ `low = mid + 1 = 7` |

* Loop terminates because `low (7) <= high (6)` is **false**.

* **Final Output:** `-1`.

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(\log n)$

  * In every iteration of the `while` loop, we identify one sorted half and determine in $\mathcal{O}(1)$ time whether `target` falls inside it, halving the search interval `[low, high]`.

* **Space Complexity:** $\mathcal{O}(1)$

  * Executed iteratively using only four primitive integer variables (`n`, `low`, `high`, `mid`). No extra memory or recursion stack is used.

## 5. Edge Cases Handled

1. **Unrotated Sorted Array (`nums = [1, 2, 3, 4, 5]`, `target = 4`):**

   * `nums[low] <= nums[mid]` holds true on every step, behaving identically to standard binary search.

2. **Two-Element Rotated Array (`nums = [3, 1]`, `target = 1`):**

   * Iteration 1: `low = 0, high = 1, mid = 0` (`nums[0] = 3`). `nums[0] <= nums[0]` is true, `3 <= 1 <= 3` is false $\rightarrow$ `low = 1`.

   * Iteration 2: `low = 1, high = 1, mid = 1` (`nums[1] = 1`). Matches `target` and returns `1`.

3. **Single-Element Array (`nums = [1]`, `target = 0`):**

   * `low = 0, high = 0, mid = 0`. `nums[0] != 0`, updates `high = -1`, loop exits and returns `-1`.