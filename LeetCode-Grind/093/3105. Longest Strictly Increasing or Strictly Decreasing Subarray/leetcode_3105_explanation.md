# LeetCode 3105: Longest Strictly Increasing or Strictly Decreasing Subarray - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We need to find the maximum length of a **contiguous subarray** that is either:
  * **Strictly Increasing:** $\text{nums}[i] > \text{nums}[i - 1]$ for all consecutive elements in the subarray.
  * **Strictly Decreasing:** $\text{nums}[i] < \text{nums}[i - 1]$ for all consecutive elements in the subarray.
* Note the word **strictly**: equal adjacent elements ($\text{nums}[i] == \text{nums}[i - 1]$) break both strictly increasing and strictly decreasing streaks.
* A single element by itself is trivially both strictly increasing and strictly decreasing of length $1$. Because the constraint guarantees $n \ge 1$, the minimum possible answer is always $1$.
* Instead of generating all $\mathcal{O}(n^2)$ subarrays, we can maintain two running streak counters (`inc` and `dec`) in a single linear pass:
  * `inc`: Length of the current strictly increasing subarray ending at index $i$.
  * `dec`: Length of the current strictly decreasing subarray ending at index $i$.
  * `ans`: Global maximum length recorded so far across both streaks.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int inc = 1 ;
        int dec = 1 ;
        int ans = 1 ;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                inc++ ;
                dec = 1 ;
            }

            else if ( nums[i] < nums[i - 1])
            {
                dec++ ;
                inc = 1 ;
            }

            else
            {
                inc = 1 ;
                dec = 1 ;
            }

            ans = max (ans, max (inc, dec )) ;
        }

        return ans ;
    }
};
```

### Detailed Execution Flow:

1. **Initialization (`inc = 1, dec = 1, ans = 1`):**
   * Starting at index $0$, the first element alone forms a valid monotonic subarray of length $1$.
2. **State Transitions (`i` from $1$ to $n - 1$):**
   * **Strictly Increasing (`nums[i] > nums[i - 1]`):** The increasing streak extends (`inc++`), while any previous decreasing streak ends and resets to the current element (`dec = 1`).
   * **Strictly Decreasing (`nums[i] < nums[i - 1]`):** The decreasing streak extends (`dec++`), while any previous increasing streak ends and resets to the current element (`inc = 1`).
   * **Equal Elements (`nums[i] == nums[i - 1]`):** Neither strict condition holds, so both streaks reset to $1$ (`inc = 1`, `dec = 1`).
3. **Updating Global Maximum:**
   * At the end of every iteration, `ans = max(ans, max(inc, dec))` captures the longest streak seen up to index $i$.

---

## 3. Comprehensive Dry Run

### Test Case 1: `nums = [1, 4, 3, 3, 2]`
* Initial state: $n = 5$, `inc = 1`, `dec = 1`, `ans = 1`

| Index ($i$) | Comparison (`nums[i]` vs `nums[i-1]`) | Condition Met | `inc` | `dec` | `ans = max(ans, max(inc, dec))` | Active Streak Subarray |
| :--- | :--- | :--- | :---: | :---: | :---: | :--- |
| **Start** | — | Initial | $1$ | $1$ | $1$ | `[1]` |
| **1** | $4 > 1$ | `nums[i] > nums[i - 1]` | $2$ | $1$ | $\max(1, \max(2, 1)) = 2$ | `[1, 4]` (inc) |
| **2** | $3 < 4$ | `nums[i] < nums[i - 1]` | $1$ | $2$ | $\max(2, \max(1, 2)) = 2$ | `[4, 3]` (dec) |
| **3** | $3 == 3$ | `else` (Equal) | $1$ | $1$ | $\max(2, \max(1, 1)) = 2$ | `[3]` (reset) |
| **4** | $2 < 3$ | `nums[i] < nums[i - 1]` | $1$ | $2$ | $\max(2, \max(1, 2)) = 2$ | `[3, 2]` (dec) |

* **Final Return Value:** `ans = 2`.

### Test Case 2: `nums = [3, 2, 1]`
* Initial state: $n = 3$, `inc = 1`, `dec = 1`, `ans = 1`

| Index ($i$) | Comparison (`nums[i]` vs `nums[i-1]`) | Condition Met | `inc` | `dec` | `ans` | Active Streak Subarray |
| :--- | :--- | :--- | :---: | :---: | :---: | :--- |
| **Start** | — | Initial | $1$ | $1$ | $1$ | `[3]` |
| **1** | $2 < 3$ | `nums[i] < nums[i - 1]` | $1$ | $2$ | $2$ | `[3, 2]` (dec) |
| **2** | $1 < 2$ | `nums[i] < nums[i - 1]` | $1$ | $3$ | $3$ | `[3, 2, 1]` (dec) |

* **Final Return Value:** `ans = 3`.

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$
  * The loop traverses the array `nums` of size $n$ exactly once from index $1$ to $n - 1$.
  * Each step performs $\mathcal{O}(1)$ comparisons and assignments.
* **Space Complexity:** $\mathcal{O}(1)$
  * Only three integer variables (`inc`, `dec`, and `ans`) are used regardless of input size. No extra data structures are allocated.

---

## 5. Edge Cases Handled

1. **Single Element Array (`nums = [5]`):**
   * $n = 1$; the `for` loop (`i = 1; i < 1`) does not execute, and `ans = 1` is returned immediately.
2. **All Elements Identical (`nums = [3, 3, 3, 3]`):**
   * Every iteration triggers the `else` branch, keeping `inc = 1` and `dec = 1`. Returns `1`.
3. **Entire Array Strictly Increasing or Decreasing (`[1, 2, 3, 4]` or `[4, 3, 2, 1]`):**
   * Either `inc` or `dec` increments continuously up to $n$, returning $n$.