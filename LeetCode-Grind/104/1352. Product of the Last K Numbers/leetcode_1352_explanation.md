# LeetCode 1352: Product of the Last K Numbers - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* A naive approach stores every incoming integer in an array and loops backward over the last $k$ elements on each `getProduct(k)` call, which takes $\mathcal{O}(k)$ time per query and $\mathcal{O}(n^2)$ worst-case time overall.
* To answer `getProduct(k)` in **$\mathcal{O}(1)$ time**, we maintain a **Running Prefix Product** array `temp`:
  * Initialize `temp` with a sentinel value `1` so multiplying the first element works cleanly and dividing by `temp[0]` yields the full product.
  * Whenever a non-zero number $x$ is added, we append $\text{temp.back()} \times x$.
  * If there are no zeros in the stream, the product of the last $k$ elements is simply:
    $$
    \frac{\text{temp}[n - 1]}{\text{temp}[n - k - 1]}
    $$
* **Handling Zeros (`nums == 0`):**
  * A `0` destroys all previous prefix products: any future `getProduct(k)` query that reaches back to or past that `0` **must** return `0`, and we cannot divide by `0` in our prefix array.
  * **Key Insight:** Whenever `0` is added, we completely **reset** `temp` by clearing it and pushing the sentinel `1` again (`temp = {1}`).
  * Now `temp.size()` equals $1 + (\text{number of non-zero elements added since the last } 0)$.
  * On `getProduct(k)`:
    * If $k \ge \text{temp.size()}$, the last $k$ elements strictly include at least one `0` that caused a reset, so immediately return `0`.
    * Otherwise, all of the last $k$ elements are non-zero, and $\text{temp}[n - 1] / \text{temp}[n - k - 1]$ yields the exact product in $\mathcal{O}(1)$ time.

---

## 2. Code Implementation Walkthrough

```cpp
class ProductOfNumbers {
private :
vector < int > temp ;

public:

    ProductOfNumbers() 
    {
        temp.push_back(1) ;
    }
    
    void add(int nums) 
    {
        if (nums == 0)
        {
            temp.clear() ;
            temp.push_back(1) ;
        }

        else 
        {
            int product = temp.back() * nums ;
            temp.push_back(product) ;
        }
    }
    
    int getProduct(int k) 
    {
        int n = temp.size() ;

        if (k >= n)
        {
            return 0 ;
        }

        return temp[n - 1] / temp[n - k - 1] ;
    }
};
```

### Detailed Logic Breakdown:

1. **Constructor (`ProductOfNumbers()`):**
   * Pushes sentinel `1` into `temp`. Since `temp` has size `1`, there are currently `0` non-zero elements recorded since initialization.
2. **`add(int nums)`:**
   * **When `nums == 0`:** Clears all prior prefix products (`temp.clear()`) and restarts with `temp = {1}`. Any query spanning across this point will now see `k >= temp.size()`.
   * **When `nums != 0`:** Multiplies the latest cumulative product (`temp.back()`) by `nums` and appends it to `temp`.
3. **`getProduct(int k)`:**
   * Let `n = temp.size()`. The number of valid non-zero elements currently stored after the last zero is `n - 1`.
   * **Zero-Inclusion Check (`if (k >= n)`):** Equivalent to `k > n - 1`, meaning `k` exceeds the number of non-zero elements since the last zero. Returns `0`.
   * **Prefix Division (`temp[n - 1] / temp[n - k - 1]`):** Cancels out the prefix product of all elements before the last `k` numbers, leaving the exact product of the last `k` numbers.

---

## 3. Comprehensive Dry Run

### Operations Sequence:
`add(3) -> add(0) -> add(2) -> add(5) -> add(4) -> getProduct(2) -> getProduct(3) -> getProduct(4) -> add(8) -> getProduct(2)`

| Step | Operation | Condition / Calculation | `temp` Vector After Step | `n = temp.size()` | Return Value |
| :--- | :--- | :--- | :--- | :---: | :---: |
| **0** | `ProductOfNumbers()` | Push sentinel `1` | `[1]` | $1$ | `null` |
| **1** | `add(3)` | `3 != 0` $\rightarrow 1 \times 3 = 3$ | `[1, 3]` | $2$ | `null` |
| **2** | `add(0)` | `0 == 0` $\rightarrow$ Clear & push `1` | `[1]` | $1$ | `null` |
| **3** | `add(2)` | `2 != 0` $\rightarrow 1 \times 2 = 2$ | `[1, 2]` | $2$ | `null` |
| **4** | `add(5)` | `5 != 0` $\rightarrow 2 \times 5 = 10$ | `[1, 2, 10]` | $3$ | `null` |
| **5** | `add(4)` | `4 != 0` $\rightarrow 10 \times 4 = 40$ | `[1, 2, 10, 40]` | $4$ | `null` |
| **6** | `getProduct(2)` | $2 \ge 4$ (False) $\rightarrow \text{temp}[3] / \text{temp}[4 - 2 - 1] = 40 / \text{temp}[1] = 40 / 2$ | `[1, 2, 10, 40]` | $4$ | **`20`** |
| **7** | `getProduct(3)` | $3 \ge 4$ (False) $\rightarrow \text{temp}[3] / \text{temp}[4 - 3 - 1] = 40 / \text{temp}[0] = 40 / 1$ | `[1, 2, 10, 40]` | $4$ | **`40`** |
| **8** | `getProduct(4)` | $4 \ge 4$ (**True**) $\rightarrow$ Zero lies within last $4$ elements | `[1, 2, 10, 40]` | $4$ | **`0`** |
| **9** | `add(8)` | `8 != 0` $\rightarrow 40 \times 8 = 320$ | `[1, 2, 10, 40, 320]` | $5$ | `null` |
| **10** | `getProduct(2)` | $2 \ge 5$ (False) $\rightarrow \text{temp}[4] / \text{temp}[5 - 2 - 1] = 320 / \text{temp}[2] = 320 / 10$ | `[1, 2, 10, 40, 320]` | $5$ | **`32`** |

---

## 4. Complexity Analysis

* **Time Complexity:**
  * `ProductOfNumbers()`: $\mathcal{O}(1)$
  * `add(int nums)`: $\mathcal{O}(1)$ amortized. Even when `temp.clear()` runs, clearing a vector of integers is $\mathcal{O}(1)$ in C++ (trivial destructors, resets size pointer to $0$), and `push_back` is amortized $\mathcal{O}(1)$.
  * `getProduct(int k)`: $\mathcal{O}(1)$ — performs one comparison and one integer division.
* **Space Complexity:** $\mathcal{O}(n)$
  * Stores at most $n + 1$ prefix products in `temp`, where $n$ is the number of non-zero elements added since the last `0` (at most the total number of `add` calls).

---

## 5. Edge Cases Handled

1. **Query Immediately After Adding `0` (`add(0)`, `getProduct(1)`):**
   * `temp` resets to `[1]`, so `n = 1`. Since `k = 1 >= 1`, `getProduct(1)` immediately returns `0`.
2. **Querying All Non-Zero Elements (`k == n - 1`):**
   * `n - k - 1` evaluates to `0`, dividing `temp[n - 1]` by the sentinel `temp[0] = 1`, cleanly returning the entire cumulative product.
3. **Multiple Consecutive Zeros (`add(0)`, `add(0)`):**
   * Each `0` simply resets `temp` back to `[1]`, keeping `n = 1` so any subsequent query spanning those zeros returns `0`.
4. **Stream of `1`s (`add(1)` repeated):**
   * `temp.back() * 1` stays `1`, preventing integer overflow and returning `1` for any valid `k`.