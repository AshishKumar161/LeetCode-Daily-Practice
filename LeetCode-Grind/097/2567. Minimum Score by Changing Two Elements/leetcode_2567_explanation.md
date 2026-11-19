# LeetCode 2567: Minimum Score by Changing Two Elements - Detailed Explanation

## 1. Problem Understanding & Core Intuition

We are given an array `nums` of length $n \ge 3$ and can modify at most **two** elements to any value we choose in order to minimize:

$$
\text{Score} = \text{High Score} + \text{Low Score}
$$

1. **Eliminating the Low Score ($\text{Low Score} = 0$):**
   * Since $n \ge 3$ and we are allowed to change up to $2$ elements, we can always set one of those modified elements equal to an existing element in `nums`.
   * Having at least two identical numbers guarantees that the minimum absolute difference between any two elements becomes $|x - x| = 0$.
   * Thus, the minimum possible **Low Score** is always $0$.

2. **Minimizing the High Score ($\max - \min$):**
   * With $\text{Low Score} = 0$, the problem reduces entirely to minimizing the range ($\max(\text{nums}) - \min(\text{nums})$) of the remaining elements after effectively removing/neutralizing $2$ extreme elements by setting them equal to remaining middle values.
   * Let the three smallest elements in the array be $s_1 \le s_2 \le s_3$ and the three largest elements be $l_1 \ge l_2 \ge l_3$.
   * There are only **3 optimal ways** to remove/replace $2$ boundary elements:
     * **Case 1 (Remove two smallest: $s_1, s_2$):** The new range is $l_1 - s_3$.
     * **Case 2 (Remove two largest: $l_1, l_2$):** The new range is $l_3 - s_1$.
     * **Case 3 (Remove one smallest $s_1$ and one largest $l_1$):** The new range is $l_2 - s_2$.

The answer is simply:

$$
\min(l_1 - s_3,\; l_2 - s_2,\; l_3 - s_1)
$$

---

## 2. Main Approach: Single-Pass Extreme Tracking ($\mathcal{O}(n)$ Time, $\mathcal{O}(1)$ Space)

### Intuition:
Instead of sorting the entire array in $\mathcal{O}(n \log n)$ time, we only care about the **3 smallest** elements ($s_1 \le s_2 \le s_3$) and the **3 largest** elements ($l_1 \ge l_2 \ge l_3$). We can find all six values in a single linear pass over `nums` using six scalar variables.

*(Note: Since constraints guarantee $1 \le \text{nums}[i] \le 10^9$, initializing $l_1 = l_2 = l_3 = 0$ and $s_1 = s_2 = s_3 = \text{INT\_MAX}$ safely captures all positive inputs.)*

### Main Code Implementation Walkthrough:

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        int n = nums.size() ;

        int s1 = INT_MAX ;
        int s2 = INT_MAX ;
        int s3 = INT_MAX ;

        int l1 = 0 ;
        int l2 = 0 ;
        int l3 = 0 ;

        for ( int i = 0 ; i < n  ; i++)
        {
            if(s1 > nums[i])
            {
                s3 = s2 ;
                s2 = s1 ;
                s1 = nums[i] ;
            }
            else if (s2 > nums[i])
            {
                s3 = s2 ;
                s2 = nums[i] ;
            } 
            else if (s3 > nums[i])
            {
                s3 = nums[i] ;
            }

            if (l1 < nums[i])
            {
                l3 = l2 ;
                l2 = l1 ;
                l1 = nums[i] ;
            }
            else if (l2 < nums[i])
            {
                l3 = l2 ;
                l2 = nums[i] ;
            }
            else if (l3 < nums[i])
            {
                l3 = nums[i] ;
            }

        }

        return min({l1 - s3 , l2 - s2 , l3 - s1 }) ;
    }
};
```

### Dry Run (Main Approach): `nums = [1, 4, 7, 8, 5]`

* Initial state:
  * Smallest: `s1 = INT_MAX`, `s2 = INT_MAX`, `s3 = INT_MAX`
  * Largest: `l1 = 0`, `l2 = 0`, `l3 = 0`

| Index ($i$) | `nums[i]` | Smallest Trio `(s1, s2, s3)` | Largest Trio `(l1, l2, l3)` | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **0** | `1` | `(1, INT_MAX, INT_MAX)` | `(1, 0, 0)` | Updates `s1` and `l1` |
| **1** | `4` | `(1, 4, INT_MAX)` | `(4, 1, 0)` | Updates `s2` and shifts `l1` |
| **2** | `7` | `(1, 4, 7)` | `(7, 4, 1)` | Updates `s3` and shifts `l1, l2` |
| **3** | `8` | `(1, 4, 7)` | `(8, 7, 4)` | `8 > s3` (no change to `s`); shifts `l1, l2` |
| **4** | `5` | `(1, 4, 5)` | `(8, 7, 5)` | Updates `s3 = 5` and `l3 = 5` |

* **Final Trio Values:**
  * Smallest: $s_1 = 1,\; s_2 = 4,\; s_3 = 5$
  * Largest: $l_1 = 8,\; l_2 = 7,\; l_3 = 5$
* **Evaluating the 3 Cases:**
  1. $l_1 - s_3 = 8 - 5 = 3$
  2. $l_2 - s_2 = 7 - 4 = 3$
  3. $l_3 - s_1 = 5 - 1 = 4$
* **Result:** $\min(\{3, 3, 4\}) = 3$.

### Complexity Analysis (Main Approach):
* **Time Complexity:** $\mathcal{O}(n)$ — Single pass through the array of length $n$ with $\mathcal{O}(1)$ comparisons per element.
* **Space Complexity:** $\mathcal{O}(1)$ — Only six integer variables are maintained; input array is not modified.

---

## 3. Alternative Approach: Sorting ($\mathcal{O}(n \log n)$ Time, $\mathcal{O}(1)$ Space)

### Intuition:
By sorting `nums` in ascending order, the three smallest elements ($s_1, s_2, s_3$) sit directly at indices `0, 1, 2`, and the three largest elements ($l_3, l_2, l_1$) sit at indices `n - 3, n - 2, n - 1`. We can immediately compute the three boundary differences and return their minimum.

### Alternative Code Implementation:

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size() ;

        sort(nums.begin() , nums.end()) ;
        int ans = 0 ;

        // two smallest remove
        int a = nums[n - 1] - nums[2] ;

        // two largest remove
        int b = nums[n-3] - nums[0] ;

        // one smallest and one largest remove
        int c = nums[n - 2] - nums[1] ;

        ans = min({a ,b , c}) ;

        return ans ;
    }
};
```

### Dry Run (Sorting Approach): `nums = [1, 4, 7, 8, 5]`
1. After `sort(nums.begin(), nums.end())`: `nums = [1, 4, 5, 7, 8]`, $n = 5$.
2. `a = nums[4] - nums[2] = 8 - 5 = 3` (removing `1` and `4`).
3. `b = nums[2] - nums[0] = 5 - 1 = 4` (removing `7` and `8`).
4. `c = nums[3] - nums[1] = 7 - 4 = 3` (removing `1` and `8`).
5. `ans = min({3, 4, 3}) = 3`.

### Complexity Analysis (Sorting Approach):
* **Time Complexity:** $\mathcal{O}(n \log n)$ — Dominated by `std::sort`.
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space ($\mathcal{O}(\log n)$ recursion stack space used by introsort).

---

## 4. Comparison of Both Approaches

| Metric | Main Approach: Single-Pass Tracking | Alternative Approach: Sorting |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(n)$ | $\mathcal{O}(n \log n)$ |
| **Space Complexity** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ auxiliary ($\mathcal{O}(\log n)$ stack) |
| **Mutates Input?** | No | Yes (sorts `nums` in-place) |
| **Core Idea** | Tracks top 3 min & max in one scan | Sorts array to index boundary elements |

---

## 5. Edge Cases Handled

1. **Minimum Array Size ($n = 3$, e.g., `nums = [1, 4, 3]`):**
   * $s_1 = 1, s_2 = 3, s_3 = 4$ and $l_1 = 4, l_2 = 3, l_3 = 1$.
   * $l_1 - s_3 = 0$, $l_2 - s_2 = 0$, $l_3 - s_1 = 0$.
   * Returns `0` (changing any two elements to equal the third makes all elements identical).
2. **Duplicate Elements (`nums = [5, 5, 5, 10]`):**
   * Proper `else if` branching ensures duplicate values populate consecutive slots (`s1 = 5, s2 = 5, s3 = 5`) rather than being skipped.
3. **Already Identical Elements (`nums = [7, 7, 7, 7]`):**
   * All differences evaluate to $7 - 7 = 0$, returning `0`.