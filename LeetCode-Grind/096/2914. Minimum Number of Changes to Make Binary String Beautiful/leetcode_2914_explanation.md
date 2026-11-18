# LeetCode 2914: Minimum Number of Changes to Make Binary String Beautiful - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given an **even-length** binary string `s` and want to partition it into contiguous substrings where:
  1. Every substring has an **even length** ($2, 4, 6, \dots$).
  2. Every substring consists entirely of identical characters (all `'0'`s or all `'1'`s).

* **Key Observation (Greedy Pair Decomposition):**
  * Any even-length uniform substring (such as `"0000"` or `"111111"`) can always be further subdivided into smaller blocks of length $2$ (`"00|00"` or `"11|11|11"`).
  * Conversely, if every adjacent pair of characters at indices $(0, 1), (2, 3), \dots, (n-2, n-1)$ is made uniform (`"00"` or `"11"`), then the entire string is trivially partitioned into valid even-length substrings of size $2$.
  * Attempting to merge adjacent pairs into larger uniform blocks of length $4$ or $6$ never reduces the number of character flips required—each mismatched pair `(s[i], s[i+1])` independently requires at least $1$ change, and matched pairs require $0$ changes.

* Therefore, the problem reduces to checking every disjoint pair $(s[2k], s[2k+1])$ and counting how many pairs have differing characters (`s[i] != s[i+1]`).

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    int minChanges(string s) {
        int n = s.size() ;
        int ans = 0 ;

        for (int i = 0 ; i < n ; i+=2 )
        {
            if (s[i] != s[i+1])
            {
                ans++ ;
            }
        }
        return ans ;
    }
};
```

### Detailed Execution Flow:

1. **Initialization:**
   * `n = s.size()`: Stores the even length of the binary string.
   * `ans = 0`: Tracks the minimum number of character changes needed.

2. **Pairwise Stride Loop (`i += 2`):**
   * The loop iterates over starting indices of adjacent pairs: $i = 0, 2, 4, \dots, n - 2$.
   * Since `n` is guaranteed to be even, `i + 1` is always a valid index within bounds ($i + 1 < n$).

3. **Pair Comparison (`s[i] != s[i+1]`):**
   * If `s[i] == s[i+1]`: The pair is already `"00"` or `"11"`, requiring $0$ changes.
   * If `s[i] != s[i+1]`: The pair is either `"01"` or `"10"`. Changing either character makes the pair uniform (`"00"` or `"11"`), so we increment `ans++`.

4. **Return:**
   * After scanning all $n / 2$ pairs, return `ans`.

---

## 3. Comprehensive Dry Run

### Test Case 1: `s = "1001"`
* $n = 4$, `ans = 0`

| Iteration | Index $i$ | Pair `(s[i], s[i+1])` | Condition `s[i] != s[i+1]` | Action on `ans` | Resulting Valid Pair Example |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | `('1', '0')` | True (`'1' != '0'`) | `ans = 0 + 1 = 1` | `"11"` |
| **2** | $2$ | `('0', '1')` | True (`'0' != '1'`) | `ans = 1 + 1 = 2` | `"00"` |

* Loop ends ($i = 4$ is not $< 4$).
* **Final Return Value:** `ans = 2` (Partitioned string: `"11|00"`).

---

### Test Case 2: `s = "110010"`
* $n = 6$, `ans = 0`

| Iteration | Index $i$ | Pair `(s[i], s[i+1])` | Condition `s[i] != s[i+1]` | Action on `ans` | Resulting Valid Pair Example |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | $0$ | `('1', '1')` | False (`'1' == '1'`) | No change (`ans = 0`) | `"11"` |
| **2** | $2$ | `('0', '0')` | False (`'0' == '0'`) | No change (`ans = 0`) | `"00"` |
| **3** | $4$ | `('1', '0')` | True (`'1' != '0'`) | `ans = 0 + 1 = 1` | `"11"` |

* **Final Return Value:** `ans = 1` (Partitioned string: `"11|00|11"`).

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$
  * The loop increments `i` by $2$ on each step, executing $n / 2$ iterations for a string of length $n$.
  * Each iteration performs an $\mathcal{O}(1)$ character comparison.

* **Space Complexity:** $\mathcal{O}(1)$
  * No extra strings, arrays, or auxiliary data structures are allocated. Only two integer variables (`n` and `ans`) are used.

---

## 5. Edge Cases Handled

1. **Minimum Length String (`s = "10"` or `s = "00"`):**
   * $n = 2$; runs a single iteration at $i = 0$, returning `1` for mismatched characters and `0` for matched characters.

2. **Already Beautiful String (`s = "0000"` or `s = "110011"`):**
   * Every pair has identical characters (`s[i] == s[i+1]`), returning `0`.

3. **Alternating Binary String (`s = "101010"`):**
   * Every pair of length $2$ mismatches (`"10"`, `"10"`, `"10"`), requiring $n / 2 = 3$ changes.