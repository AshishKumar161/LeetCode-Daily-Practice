# LeetCode 3041: Maximize Consecutive Elements in an Array After Modification - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given an array `nums` of positive integers where each element $x$ can either stay as $x$ or be increased by $1$ to become $x + 1$.
* Our goal is to select the longest possible subset of elements that form a strictly consecutive sequence ($v, v+1, v+2, \dots, v+k-1$) after sorting.
* **Key Greedy Insights:**
  1. **Sort First:** Since the final selected elements are evaluated in sorted order, sorting `nums` initially allows us to build consecutive chains greedily from smallest to largest.
  2. **Preserve Flexibility (Avoid Premature Bumping):** Leaving an element un-bumped (`bumped[k] = false`) keeps it as small as possible so future duplicates can take $x + 1$. However, if a gap of size $2$ appears (`ans[idx] + 2 == nums[i]`), we can retroactively bump a suffix of consecutive un-bumped elements by $+1$ to bridge the gap!
  3. **Record Before Retroactive Shifting:** Because bumping a suffix of un-bumped elements might break its connection to an earlier *already-bumped* prefix, we first record the current full streak length (`idx - fullStart + 1`) into `maxi` before shifting the un-bumped suffix forward.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {

        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;

        vector<int> ans ;
        vector<bool> bumped ;

        ans.push_back(nums[0]) ;
        bumped.push_back(false) ;

        int idx = 0 ;
        int maxi = 1 ;

        for (int i = 1 ; i < n ; i++) 
        {

            if (ans[idx] == nums[i]) 
            {
                ans.push_back(nums[i] + 1) ;
                bumped.push_back(true) ;
                idx++ ;
            }

            else if (ans[idx] + 1 == nums[i]) 
            {
                ans.push_back(nums[i]) ;
                bumped.push_back(false) ;
                idx++ ;
            }

            else if (ans[idx] + 2 == nums[i]) 
            {

                int fullStart = idx ;

                while (fullStart > 0 && ans[fullStart] == ans[fullStart - 1] + 1) 
                {
                    fullStart-- ;
                }

                maxi = max(maxi , idx - fullStart + 1) ;

                if (!bumped[idx]) 
                {

                    int start = idx ;

                    while (start > 0 && ans[start] == ans[start - 1] + 1 && !bumped[start - 1]) 
                    {
                        start-- ;
                    }

                    for (int k = start ; k <= idx ; k++) 
                    {
                        ans[k]++ ;
                        bumped[k] = true ;
                    }
                }

                ans.push_back(nums[i]) ;
                bumped.push_back(false) ;
                idx++ ;
            }

            else if (ans[idx] < nums[i]) 
            {
                ans.push_back(nums[i]) ;
                bumped.push_back(false) ;
                idx++ ;
            }
        }

        int count = 1 ;

        for (int i = 1 ; i < ans.size() ; i++) 
        {
            if(ans[i] == ans[i - 1] + 1) 
            {
                count++ ;
            }

            else 
            {
                count = 1 ;
            }

            maxi = max(maxi , count) ;
        }

        return maxi ;
    }
};
```

### Detailed Case Breakdown:

1. **Initialization:**
   * Sort `nums` in non-decreasing order.
   * Push `nums[0]` into `ans` with `bumped[0] = false`. `idx` tracks the index of the last element in `ans`.

2. **Case 1: `ans[idx] == nums[i]` (Duplicate Value):**
   * The value `ans[idx]` is already present at the end of our constructed chain.
   * We bump `nums[i]` to `nums[i] + 1`, append it to `ans`, mark `bumped` as `true`, and increment `idx`.

3. **Case 2: `ans[idx] + 1 == nums[i]` (Naturally Consecutive):**
   * `nums[i]` already continues the consecutive chain without modification.
   * Append `nums[i]` as-is, mark `bumped` as `false` (preserving its $+1$ capability for later), and increment `idx`.

4. **Case 3: `ans[idx] + 2 == nums[i]` (Gap of 1 Missing Integer):**
   * First, walk backward (`fullStart`) to measure the entire consecutive streak ending at `idx` and update `maxi = max(maxi, idx - fullStart + 1)` before altering any values.
   * If `ans[idx]` has not been bumped yet (`!bumped[idx]`), walk backward (`start`) as far as elements are consecutive **and** un-bumped (`!bumped[start - 1]`). Increment every element in `[start, idx]` by $1$ and mark `bumped[k] = true` so `ans[idx]` becomes `nums[i] - 1`, bridging the gap to `nums[i]`.
   * Finally, append `nums[i]` (`bumped = false`) and increment `idx`.

5. **Case 4: `ans[idx] < nums[i]` (Gap $\ge 2$, Unbridgeable):**
   * Even bumping `ans[idx]` cannot reach `nums[i]`. Start a fresh chain by appending `nums[i]` (`bumped = false`).
   * *(Note: If `ans[idx] > nums[i]`, which occurs when an earlier duplicate was already bumped to `nums[i] + 1` and another duplicate of `nums[i]` arrives, the extra copy is safely skipped.)*

6. **Final Streak Pass:**
   * Scan `ans` from left to right to find the longest contiguous consecutive sequence (`ans[i] == ans[i - 1] + 1`) and update `maxi`.

---

## 3. Comprehensive Dry Run

### Test Case 1: `nums = [2, 1, 5, 1, 1]`

1. **Sort `nums`:** `[1, 1, 1, 2, 5]`
2. **Initial State:** `ans = [1]`, `bumped = [false]`, `idx = 0`, `maxi = 1`

| Step ($i$) | `nums[i]` | Condition Matched | Action Taken | `ans` | `bumped` | `idx` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Start** | `1` | Initial | Push `1` (`false`) | `[1]` | `[F]` | `0` |
| **1** | `1` | `ans[0] == 1` | Push `1 + 1 = 2` (`true`) | `[1, 2]` | `[F, T]` | `1` |
| **2** | `1` | None (`ans[1] = 2 > 1`) | Extra duplicate skipped | `[1, 2]` | `[F, T]` | `1` |
| **3** | `2` | `ans[1] == 2` | Push `2 + 1 = 3` (`true`) | `[1, 2, 3]` | `[F, T, T]` | `2` |
| **4** | `5` | `ans[2] < 5` (`3 < 5`) | Push `5` (`false`) | `[1, 2, 3, 5]` | `[F, T, T, F]` | `3` |

3. **Final Streak Pass on `ans = [1, 2, 3, 5]`:**
   * $i = 1$: $2 == 1 + 1 \implies \text{count} = 2, \text{maxi} = 2$
   * $i = 2$: $3 == 2 + 1 \implies \text{count} = 3, \text{maxi} = 3$
   * $i = 3$: $5 \neq 3 + 1 \implies \text{count} = 1, \text{maxi} = 3$
   * **Output:** `3`.

---

### Test Case 2 (Demonstrating Retroactive Gap Bridging): `nums = [1, 2, 4, 5]`

1. **Initial State:** `ans = [1]`, `bumped = [false]`, `idx = 0`, `maxi = 1`

| Step ($i$) | `nums[i]` | Condition Matched | Action Taken | `ans` | `bumped` | `maxi` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Start** | `1` | Initial | Push `1` (`false`) | `[1]` | `[F]` | `1` |
| **1** | `2` | `ans[0] + 1 == 2` | Push `2` (`false`) | `[1, 2]` | `[F, F]` | `1` |
| **2** | `4` | `ans[1] + 2 == 4` | `fullStart = 0` (`maxi = 2`); shift `[0..1]` by `+1` $\rightarrow$ `[2, 3]`, push `4` (`false`) | `[2, 3, 4]` | `[T, T, F]` | `2` |
| **3** | `5` | `ans[2] + 1 == 5` | Push `5` (`false`) | `[2, 3, 4, 5]` | `[T, T, F, F]` | `2` |

2. **Final Streak Pass on `ans = [2, 3, 4, 5]`:**
   * Consecutive chain `[2, 3, 4, 5]` has length `4`.
   * **Output:** `4`.

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n \log n)$
  * Sorting `nums` takes $\mathcal{O}(n \log n)$ time.
  * In the main loop, each element in `ans` can only transition from `bumped[k] = false` to `bumped[k] = true` **at most once** across the entire execution. Because the `while` loops only traverse contiguous blocks of un-bumped elements (or run when a gap of $2$ occurs, which happens at most $n$ times, each amortized over disjoint segments), the total work inside the loop is amortized $\mathcal{O}(n)$.
  * The final linear scan takes $\mathcal{O}(n)$ time.
* **Space Complexity:** $\mathcal{O}(n)$
  * Auxiliary vectors `ans` and `bumped` store at most $n$ elements each, alongside $\mathcal{O}(\log n)$ sorting stack space.

---

## 5. Edge Cases Handled

1. **Single Element Array (`nums = [7]`):**
   * `ans = [7]`, both loops do not execute, returns `maxi = 1`.
2. **All Elements Identical (`nums = [3, 3, 3, 3]`):**
   * First `3` stays `3`, second `3` becomes `4`, remaining `3`s are skipped since `ans[idx] = 4 > 3`. Returns `2` (`[3, 4]`).
3. **Already Bumped Suffix Before Gap of 2 (`nums = [1, 1, 4]`):**
   * After `[1, 1]`, `ans = [1, 2]` with `bumped = [false, true]`. When `4` arrives (`2 + 2 == 4`), `fullStart` records `maxi = 2`, and because `bumped[1]` is `true`, `[1, 2]` is not shifted into `[2, 3]` (which would duplicate `2`). `4` starts a new segment, preserving `maxi = 2`.