# LeetCode 69: Sqrt(x) - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given a non-negative integer $x$ and need to find $\lfloor \sqrt{x} \rfloor$—the largest integer $m$ such that:

  $$
  m^2 \le x
  $$

* Notice that the function $f(m) = m^2$ is **strictly monotonically increasing** for all non-negative integers $m \ge 0$.
* Because the answer always lies in the sorted search space $[0, x]$, we can apply **Binary Search on Answer** instead of linearly checking $0, 1, 2, \dots$:
  * Compute the candidate midpoint `mid = low + (high - low) / 2`.
  * Compare $\text{mid}^2$ against $x$:
    * If $\text{mid}^2 == x$: `mid` is the exact square root $\rightarrow$ return `mid`.
    * If $\text{mid}^2 > x$: `mid` (and every number greater than `mid`) is too large $\rightarrow$ search the left half (`high = mid - 1`).
    * If $\text{mid}^2 < x$: `mid` is a valid candidate, but a larger integer might still satisfy $m^2 \le x$ $\rightarrow$ search the right half (`low = mid + 1`).

* **Why Returning `high` Works When $x$ Is Not a Perfect Square:**
  * Whenever the `while (low <= high)` loop terminates without finding an exact match, `low` and `high` have crossed so that `high = low - 1`.
  * At termination, every integer $\le \text{high}$ has a square strictly less than $x$, and every integer $\ge \text{low}$ has a square strictly greater than $x$.
  * Therefore, `high` is guaranteed to be the largest integer satisfying $\text{high}^2 \le x$, which is $\lfloor \sqrt{x} \rfloor$.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int low = 0 ;
        int high = x ;

        while ( low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if (1ll * mid * mid == x)
            {
                return mid ;
            }

            if (1ll * mid * mid > x)
            {
                high = mid - 1 ;
            }

            if (1ll * mid * mid < x)
            {
                low = mid + 1 ;
            }
        }

        return high ;
    }
};
```

### Key Implementation Details:

1. **Preventing 32-Bit Signed Integer Overflow (`1ll * mid * mid`):**
   * Since $x$ can be as large as $2^{31} - 1$ (`2147483647`), the initial midpoint `mid` can be $\approx 1.07 \times 10^9$.
   * Squaring `mid * mid` in 32-bit `int` would overflow immediately ($\approx 1.15 \times 10^{18} > 2.14 \times 10^9$).
   * Multiplying by `1ll` (a 64-bit `long long` literal) first promotes the multiplication to 64-bit `long long` (max value $\approx 9.22 \times 10^{18}$), safely holding $\text{mid}^2$ without overflow.
2. **Overflow-Safe Midpoint Formula:**
   * Using `mid = low + (high - low) / 2` avoids overflow in `(low + high)` when `low` and `high` are close to $2^{31} - 1$.

---

## 3. Comprehensive Dry Run

### Test Case 1: Perfect Square (`x = 4`)

* Initial state: `low = 0`, `high = 4`

| Iteration | `low` | `high` | `mid = low + (high - low) / 2` | `1ll * mid * mid` | Comparison with `x = 4` | Action |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **1** | $0$ | $4$ | $0 + (4 - 0) / 2 = 2$ | $4$ | $4 == 4$ | **Return `mid = 2`** |

* **Final Output:** `2`.

### Test Case 2: Non-Perfect Square (`x = 8`)

* Initial state: `low = 0`, `high = 8`

| Iteration | `low` | `high` | `mid = low + (high - low) / 2` | `1ll * mid * mid` | Comparison with `x = 8` | Boundary Update |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **1** | $0$ | $8$ | $0 + (8 - 0) / 2 = 4$ | $16$ | $16 > 8$ | `high = mid - 1 = 3` |
| **2** | $0$ | $3$ | $0 + (3 - 0) / 2 = 1$ | $1$ | $1 < 8$ | `low = mid + 1 = 2` |
| **3** | $2$ | $3$ | $2 + (3 - 2) / 2 = 2$ | $4$ | $4 < 8$ | `low = mid + 1 = 3` |
| **4** | $3$ | $3$ | $3 + (3 - 3) / 2 = 3$ | $9$ | $9 > 8$ | `high = mid - 1 = 2` |

* Loop terminates because `low (3) <= high (2)` is **false**.
* Returns `high = 2`.
* **Final Output:** `2` (since $\sqrt{8} \approx 2.82842$, floored to $2$).

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(\log x)$
  * The search space $[0, x]$ is halved on every iteration. Even for the maximum constraint $x = 2^{31} - 1$, the loop executes at most $31$ iterations.
* **Space Complexity:** $\mathcal{O}(1)$
  * Uses only three primitive integer variables (`low`, `high`, `mid`). No extra memory or recursion stack is required.

---

## 5. Edge Cases Handled

1. **Zero Input (`x = 0`):**
   * `low = 0`, `high = 0`, `mid = 0`. `1ll * 0 * 0 == 0` returns `0` on the first iteration.
2. **One Input (`x = 1`):**
   * Iteration 1: `mid = 0`, `0 < 1` $\rightarrow$ `low = 1`.
   * Iteration 2: `mid = 1`, `1 == 1` $\rightarrow$ returns `1`.
3. **Maximum 32-Bit Signed Integer (`x = 2147483647`):**
   * `1ll * mid * mid` avoids 32-bit overflow when squaring large midpoints (up to $1073741823^2 \approx 1.15 \times 10^{18}$).
   * Converges cleanly to `high = 46340` ($46340^2 = 2147395600 \le 2147483647 < 46341^2 = 2147488281$).