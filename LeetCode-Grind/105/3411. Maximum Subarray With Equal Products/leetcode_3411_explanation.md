# LeetCode 3411: Maximum Subarray With Equal Products - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We need to find the longest contiguous subarray `arr` of `nums` that satisfies the **product equivalence** condition:
  $$
  \text{prod}(\text{arr}) == \text{lcm}(\text{arr}) \times \text{gcd}(\text{arr})
  $$

* Because $2 \le \text{nums.length} \le 100$, checking subarrays with a nested loop `(i, j)` is fast enough, **provided we prevent integer overflow** when multiplying elements into `nums_prod`.

* **Key Observation (Precomputing an Upper Bound `max_prod`):**
  1. For any subarray `arr` of `nums`, its LCM can never exceed the LCM of the entire array (`max_lcm`).
  2. Its GCD can never exceed the maximum single element in the array (`max_val`).
  3. Therefore, for **every** possible subarray `arr` of `nums`, the right-hand side of the equation is strictly bounded above by:
     $$
     \text{lcm}(\text{arr}) \times \text{gcd}(\text{arr}) \le \text{max\_lcm} \times \text{max\_val} = \text{max\_prod}
     $$
  4. Since all elements in `nums` are positive ($\ge 1$), `nums_prod` only stays the same or grows as `j` moves right. The moment `nums_prod > max_prod`, it is mathematically impossible for `nums_prod` to equal `nums_lcm * nums_gcd` for any further extension of `j`—so we immediately `break`.

* **Why This Eliminates Overflow Completely:**
  * Since $1 \le \text{nums}[i] \le 10$, the worst-case `max_lcm` is $\text{lcm}(1, 2, \dots, 10) = 2520$, and `max_val` $\le 10$.
  * Thus `max_prod` $\le 2520 \times 10 = 25200$.
  * Right before `break` triggers, `nums_prod` can be at most $25200 \times 10 = 252000$, which fits effortlessly inside a `long long` (and even a standard 32-bit `int`).

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;

        long long max_lcm = 1 ;
        int max_val = 0 ;

        for (int x : nums)
        {
            max_lcm = lcm(max_lcm , (long long) x) ;
            max_val = max(max_val , x) ;
        }

        long long max_prod = max_lcm * max_val ;

        for (int i = 0 ; i < n ; i++)
        {
            long long nums_prod = 1 ;
            long long nums_lcm = 1 ;
            long long nums_gcd = 0 ;

            for (int j = i ; j < n ; j++)
            {
                nums_prod *= nums[j] ;

                nums_lcm = lcm(nums_lcm , (long long) nums[j]) ;
                nums_gcd = gcd(nums_gcd , (long long) nums[j]) ;

                if (nums_prod == nums_lcm * nums_gcd)
                {
                    ans = max(ans , j - i + 1) ;
                }

                if (nums_prod > max_prod)
                {
                    break ;
                }
            }
        }

        return ans ;
    }
};
```

### Detailed Execution Flow:

1. **Global Bound Precomputation (`max_lcm`, `max_val`, `max_prod`):**
   * Traverse `nums` once to calculate the LCM of all elements (`max_lcm`) and the largest element (`max_val`).
   * Compute `max_prod = max_lcm * max_val`, establishing the ceiling that no valid subarray product can exceed.

2. **Subarray Expansion (`i` and `j` Loops):**
   * For each starting index `i`, initialize:
     * `nums_prod = 1` (multiplicative identity)
     * `nums_lcm = 1` ($\text{lcm}(1, x) = x$)
     * `nums_gcd = 0` ($\gcd(0, x) = x$)
   * For each ending index `j` from `i` to `n - 1`:
     * Multiply `nums_prod` by `nums[j]` and update `nums_lcm` and `nums_gcd`.
     * If `nums_prod == nums_lcm * nums_gcd`, update `ans = max(ans, j - i + 1)`.
     * If `nums_prod > max_prod`, `break` out of the inner loop immediately to avoid unnecessary iterations and integer overflow.

---

## 3. Comprehensive Dry Run

### Test Case 1: `nums = [2, 3, 4, 5, 6]` ($n = 5$)

#### Step 1: Precomputation
* `max_lcm = lcm(2, 3, 4, 5, 6) = 60`
* `max_val = 6`
* `max_prod = 60 * 6 = 360`

#### Step 2: Subarray Trace

| Start `i` | End `j` | Subarray | `nums_prod` | `nums_lcm` | `nums_gcd` | `lcm * gcd` | Match? | `nums_prod > 360`? | `ans` |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **0** | **0** | `[2]` | $2$ | $2$ | $2$ | $4$ | No | No | $0$ |
| **0** | **1** | `[2, 3]` | $6$ | $6$ | $1$ | $6$ | **Yes** (len $2$) | No | $2$ |
| **0** | **2** | `[2, 3, 4]` | $24$ | $12$ | $1$ | $12$ | No | No | $2$ |
| **0** | **3** | `[2, 3, 4, 5]` | $120$ | $60$ | $1$ | $60$ | No | No | $2$ |
| **0** | **4** | `[2, 3, 4, 5, 6]` | $720$ | $60$ | $1$ | $60$ | No | **Yes (`break`)** | $2$ |
| **1** | **1** | `[3]` | $3$ | $3$ | $3$ | $9$ | No | No | $2$ |
| **1** | **2** | `[3, 4]` | $12$ | $12$ | $1$ | $12$ | **Yes** (len $2$) | No | $2$ |
| **1** | **3** | `[3, 4, 5]` | $60$ | $60$ | $1$ | $60$ | **Yes** (len $3$) | No | $3$ |
| **1** | **4** | `[3, 4, 5, 6]` | $360$ | $60$ | $1$ | $60$ | No | No | $3$ |
| **2** | **2** | `[4]` | $4$ | $4$ | $4$ | $16$ | No | No | $3$ |
| **2** | **3** | `[4, 5]` | $20$ | $20$ | $1$ | $20$ | **Yes** (len $2$) | No | $3$ |
| **2** | **4** | `[4, 5, 6]` | $120$ | $60$ | $1$ | $60$ | No | No | $3$ |
| **3** | **3** | `[5]` | $5$ | $5$ | $5$ | $25$ | No | No | $3$ |
| **3** | **4** | `[5, 6]` | $30$ | $30$ | $1$ | $30$ | **Yes** (len $2$) | No | $3$ |
| **4** | **4** | `[6]` | $6$ | $6$ | $6$ | $36$ | No | No | $3$ |

* **Final Return Value:** `ans = 3` (subarray `[3, 4, 5]`).

---

### Test Case 2: `nums = [1, 2, 1, 2, 1, 1, 1]` ($n = 7$)

#### Step 1: Precomputation
* `max_lcm = lcm(1, 2) = 2`, `max_val = 2`, `max_prod = 2 * 2 = 4`

#### Step 2: Key Subarray Trace from `i = 2`

| End `j` | Subarray | `nums_prod` | `nums_lcm` | `nums_gcd` | `lcm * gcd` | Match? | Length |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **2** | `[1]` | $1$ | $1$ | $1$ | $1$ | **Yes** | $1$ |
| **3** | `[1, 2]` | $2$ | $2$ | $1$ | $2$ | **Yes** | $2$ |
| **4** | `[1, 2, 1]` | $2$ | $2$ | $1$ | $2$ | **Yes** | $3$ |
| **5** | `[1, 2, 1, 1]` | $2$ | $2$ | $1$ | $2$ | **Yes** | $4$ |
| **6** | `[1, 2, 1, 1, 1]` | $2$ | $2$ | $1$ | $2$ | **Yes** | $5$ |

* **Final Return Value:** `ans = 5`.

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n^2 \log M)$
  * The precomputation pass takes $\mathcal{O}(n \log M)$ time, where $M \le 2520$ is the maximum possible LCM of numbers in $[1, 10]$.
  * The nested loops inspect at most $\frac{n(n + 1)}{2}$ subarrays (for example, when all elements are `1`), and each `gcd`/`lcm` computation takes $\mathcal{O}(\log M)$ (effectively $\mathcal{O}(1)$).
  * For arrays containing numbers $\ge 2$, the `nums_prod > max_prod` break prunes each inner loop after at most $\approx \log_2(25200) \approx 15$ non-one elements.

* **Space Complexity:** $\mathcal{O}(1)$
  * Only scalar integer variables (`n`, `ans`, `max_lcm`, `max_val`, `max_prod`, `nums_prod`, `nums_lcm`, `nums_gcd`) are allocated.

---

## 5. Edge Cases Handled

1. **Any Pair of Elements (`[a, b]`):**
   * By the identity $a \times b = \text{lcm}(a, b) \times \gcd(a, b)$, every subarray of length $2$ is always product equivalent, ensuring `ans >= 2` whenever $n \ge 2$.

2. **All Elements Equal to `1` (`nums = [1, 1, ..., 1]`):**
   * `max_lcm = 1`, `max_val = 1`, `max_prod = 1`.
   * `nums_prod` stays `1` for the entire array, never triggering `nums_prod > max_prod`, and correctly returns `n`.

3. **Preventing Signed Overflow on Long Arrays:**
   * Because `nums_prod` stops immediately once it exceeds `max_prod` ($\le 25200$), `nums_prod` stays strictly below $252000$ even when $n = 100$ and all elements are $10$.