# LeetCode 2124: Check if All A's Appears Before All B's - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We are given a string `s` composed strictly of `'a'` and `'b'` characters.
* Every `'a'` appearing before every `'b'` means the string must follow the pattern `"a...ab...b"` (where either the `'a'` section or the `'b'` section can be empty).
* **Key Observation (Adjacent Inversion Check):**
  * For any `'a'` to appear *after* a `'b'`, there must be at least one transition point in the string where a `'b'` is immediately followed by an `'a'` (`"ba"`).
  * In other words, `s` is invalid **if and only if** `"ba"` appears as an adjacent pair anywhere in `s`:
    $$\exists\, i \in [0, n - 2] \text{ such that } s[i] == \text{'b'} \land s[i + 1] == \text{'a'}$$
  * If no `"ba"` substring exists, all `'a'`s strictly precede all `'b'`s (or only one type of character exists), so the string is valid.

---

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    bool checkString(string s) {
        int n = s.size() ;

        for (int i = 0 ; i < n - 1 ; i++)
        {
            if (s[i] == 'b' && s[i + 1] == 'a')
            {
                return false ;
            }
        }

        return true ;
    }
};
```

### Detailed Logic Breakdown:
1. **Loop Bounds (`i < n - 1`):**
   * We iterate from `i = 0` up to `n - 2` so that `s[i + 1]` always accesses a valid character within bounds.
   * When $n = 1$, `n - 1 = 0`, so the loop safely skips execution and returns `true`.
2. **Adjacent Pair Verification (`s[i] == 'b' && s[i + 1] == 'a'`):**
   * Checks whether a `'b'` is immediately followed by an `'a'`.
   * If found, we can terminate early and immediately return `false`.
3. **Default Return (`return true;`):**
   * If the entire string is scanned without encountering `"ba"`, return `true`.

---

## 3. Comprehensive Dry Run

### Test Case 1: `s = "aaabbb"` ($n = 6$)

| Index ($i$) | Pair `(s[i], s[i+1])` | Condition `s[i] == 'b' && s[i + 1] == 'a'` | Action |
| :--- | :--- | :--- | :--- |
| **0** | `('a', 'a')` | False | Continue |
| **1** | `('a', 'a')` | False | Continue |
| **2** | `('a', 'b')` | False | Continue |
| **3** | `('b', 'b')` | False | Continue |
| **4** | `('b', 'b')` | False | Continue |

* Loop ends ($i = 5$ is not $< 5$).
* **Final Output:** `true`.

### Test Case 2: `s = "abab"` ($n = 4$)

| Index ($i$) | Pair `(s[i], s[i+1])` | Condition `s[i] == 'b' && s[i + 1] == 'a'` | Action |
| :--- | :--- | :--- | :--- |
| **0** | `('a', 'b')` | False | Continue |
| **1** | `('b', 'a')` | **True** (`'b'` followed by `'a'`) | **Return `false` immediately** |

* **Final Output:** `false`.

---

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$
  * In the worst case (when the string is valid or the `"ba"` pair appears at the very end), we inspect $n - 1$ adjacent character pairs once.
  * In the best case, the loop exits early as soon as `"ba"` is encountered.
* **Space Complexity:** $\mathcal{O}(1)$
  * Uses only primitive integer variables (`n` and `i`). No extra data structures are allocated.

---

## 5. Edge Cases Handled

1. **Single Character (`s = "a"` or `s = "b"`):**
   * $n = 1 \implies i < 0$ is false; loop does not run and returns `true`.
2. **Only `'a'`s or Only `'b'`s (`s = "aaaa"` or `s = "bbb"`):**
   * No `"ba"` transition exists; returns `true` (vacuously true when no `'a'`s or no `'b'`s are present).
3. **Inversion at the Very End (`s = "aabba"`):**
   * Detected at $i = 3$ (`s[3] == 'b' && s[4] == 'a'`), returning `false`.