# LeetCode 1614: Maximum Nesting Depth of the Parentheses - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given a guaranteed **valid parentheses string (VPS)** containing arithmetic characters (`+`, `-`, `*`, `/`, digits) along with parentheses `(` and `)`.
* We need to determine the maximum nesting depth—the deepest level of nested parentheses encountered at any point in the string.
* Because the string is already guaranteed to be a valid parentheses string:
  * An opening parenthesis `'('` represents going one level deeper into the nesting hierarchy ($\text{depth} \leftarrow \text{depth} + 1$).
  * A closing parenthesis `')'` represents closing the most recently opened nesting level ($\text{depth} \leftarrow \text{depth} - 1$).
  * All other characters (digits and mathematical operators) do not affect parentheses depth and can be safely ignored.
* While a stack could be used to push and pop open brackets, we only need to know the *count* of active open brackets at any given moment. Thus, a single integer counter `depth` together with a running maximum `ans` suffices.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0 ;
        int ans = 0 ;

        for (int i = 0; i < s.length() ; i++)
        {
            if (s[i] == '(')
            {
                depth++ ;
                ans = max (ans, depth) ;
            }
            else if ( s[i] == ')')
            {
                depth-- ;
            }
        }

        return ans ;
    }
};
```

### Detailed Execution Flow:
1. **Initialize State:**
   * `depth = 0`: Tracks the current number of unmatched open parentheses at index `i`.
   * `ans = 0`: Tracks the maximum value that `depth` has achieved throughout the traversal.
2. **Character-by-Character Iteration:**
   * If `s[i] == '('`:
     * Increment `depth` by $1$.
     * Update `ans = max(ans, depth)` immediately, recording any new peak depth.
   * If `s[i] == ')'`:
     * Decrement `depth` by $1$ as an open scope has just been closed.
   * Any other character (digit or operator):
     * Ignored by the `if-else if` conditions; `depth` remains unchanged.
3. **Return:**
   * Return `ans`, which stores the maximum nesting depth recorded.

---

## 3. Comprehensive Dry Run

### Test Case: `s = "(1+(2*3)+((8)/4))+1"`

* Initial state: `depth = 0`, `ans = 0`

| Index $i$ | Character `s[i]` | Condition Met | Action on `depth` | Action on `ans` (`max(ans, depth)`) | Current Depth |
| :---: | :---: | :---: | :---: | :---: | :---: |
| **0** | `'('` | `s[i] == '('` | `depth = 0 + 1 = 1` | `ans = max(0, 1) = 1` | $1$ |
| **1** | `'1'` | Ignored | None | None | $1$ |
| **2** | `'+'` | Ignored | None | None | $1$ |
| **3** | `'('` | `s[i] == '('` | `depth = 1 + 1 = 2` | `ans = max(1, 2) = 2` | $2$ |
| **4** | `'2'` | Ignored | None | None | $2$ |
| **5** | `'*'` | Ignored | None | None | $2$ |
| **6** | `'3'` | Ignored | None | None | $2$ |
| **7** | `')'` | `s[i] == ')'` | `depth = 2 - 1 = 1` | None | $1$ |
| **8** | `'+'` | Ignored | None | None | $1$ |
| **9** | `'('` | `s[i] == '('` | `depth = 1 + 1 = 2` | `ans = max(2, 2) = 2` | $2$ |
| **10** | `'('` | `s[i] == '('` | `depth = 2 + 1 = 3` | `ans = max(2, 3) = 3` | **$3$ (Peak)** |
| **11** | `'8'` | Ignored | None | None | $3$ |
| **12** | `')'` | `s[i] == ')'` | `depth = 3 - 1 = 2` | None | $2$ |
| **13** | `'/'` | Ignored | None | None | $2$ |
| **14** | `'4'` | Ignored | None | None | $2$ |
| **15** | `')'` | `s[i] == ')'` | `depth = 2 - 1 = 1` | None | $1$ |
| **16** | `')'` | `s[i] == ')'` | `depth = 1 - 1 = 0` | None | $0$ |
| **17** | `'+'` | Ignored | None | None | $0$ |
| **18** | `'1'` | Ignored | None | None | $0$ |

* **Final Return Value:** `ans = 3`.

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$
  * We perform a single linear traversal over the string `s` of length $n$.
  * At each character, only constant time $\mathcal{O}(1)$ operations (comparisons, arithmetic updates, and `max`) are executed.
* **Space Complexity:** $\mathcal{O}(1)$
  * No auxiliary data structures (like a `std::stack`) are allocated.
  * Only two scalar integer variables (`depth` and `ans`) are maintained.

---

## 5. Edge Cases Handled

1. **No Parentheses Present (`s = "1+2"`):**
   * Neither `'('` nor `')'` is found.
   * `depth` stays $0$, `ans` stays $0$. Returns `0`.
2. **Consecutive Nested Parentheses (`s = "((()))"`):**
   * `depth` increments sequentially: $1 \rightarrow 2 \rightarrow 3$.
   * `ans` captures $3$, then `depth` decrements back to $0$. Returns `3`.
3. **Sequential / Disjoint Parentheses (`s = "()()()"`):**
   * `depth` repeatedly toggles between $0$ and $1$.
   * `ans` never exceeds $1$. Returns `1`.