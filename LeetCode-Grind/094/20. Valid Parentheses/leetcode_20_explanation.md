# LeetCode 20: Valid Parentheses - Detailed Explanation

## 1. Problem Understanding & Core Intuition

* We need to verify whether a string consisting exclusively of brackets (`()`, `{}`, `[]`) is properly balanced and nested in the correct **Last-In, First-Out (LIFO)** order.
* Whenever a closing bracket appears, it **must** match the most recently opened, still-unclosed bracket.
* A **Stack** (`std::stack<char>`) is the ideal data structure for this behavior:
  * **Opening Brackets (`'('`, `'{'`, `'['`):** Push onto the stack to remember that they need to be closed later.
  * **Closing Brackets (`')'`, `'}'`, `']'`):**
    * If the stack is empty, there is no matching opening bracket available $\rightarrow$ invalid (`false`).
    * Check `st.top()`. If it is the corresponding opening bracket of the same type, pop it off the stack (the pair is successfully closed). Otherwise, the order or type is mismatched $\rightarrow$ invalid (`false`).
  * **End of String:** After processing all characters, the stack must be completely empty (`st.empty()`). If any opening brackets remain unclosed on the stack, return `false`.

## 2. Code Implementation Walkthrough

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }

            else
            {
                if (st.empty())
                {
                    return false;
                }

                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == '}' && st.top() == '{') ||
                    (s[i] == ']' && st.top() == '['))
                {

                    st.pop();
                }

                else
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
```

### Detailed Logic Breakdown:

1. **Stack Initialization (`stack<char> st;`):**
   * Stores opening brackets encountered while scanning left to right.
2. **Handling Opening Brackets:**
   * `if (s[i] == '(' || s[i] == '{' || s[i] == '[')` pushes the character onto `st`.
3. **Handling Closing Brackets (`else` block):**
   * **Empty Stack Guard (`if (st.empty())`):** Prevents runtime undefined behavior from calling `st.top()` on an empty stack when a closing bracket appears with no prior opening bracket.
   * **Pair Validation:** Checks all three valid combinations: `')'` with `'('`, `'}'` with `'{'`, and `']'` with `'['`. If matched, `st.pop()` removes the resolved opening bracket.
   * **Mismatch Exit:** If `st.top()` does not match `s[i]`, immediately returns `false`.
4. **Final Verification (`return st.empty();`):**
   * Returns `true` only if every opening bracket was matched and popped; returns `false` if unclosed brackets remain.

## 3. Comprehensive Dry Run

### Test Case 1: `s = "([])"` (Valid Nested Brackets)

| Index ($i$) | Character `s[i]` | Action Taken | Stack `st` (Bottom $\rightarrow$ Top) | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Start** | — | Initialize empty stack | `[]` | Valid |
| **0** | `'('` | Opening bracket $\rightarrow$ `st.push('(')` | `['(']` | Valid |
| **1** | `'['` | Opening bracket $\rightarrow$ `st.push('[')` | `['(', '[']` | Valid |
| **2** | `']'` | Matches `st.top() == '['` $\rightarrow$ `st.pop()` | `['(']` | Valid |
| **3** | `')'` | Matches `st.top() == '('` $\rightarrow$ `st.pop()` | `[]` | Valid |

* Loop ends; `st.empty()` evaluates to `true`.
* **Final Output:** `true`.

### Test Case 2: `s = "(]"` (Mismatched Type)

| Index ($i$) | Character `s[i]` | Action Taken | Stack `st` (Bottom $\rightarrow$ Top) | Status |
| :--- | :--- | :--- | :--- | :--- |
| **0** | `'('` | Opening bracket $\rightarrow$ `st.push('(')` | `['(']` | Valid |
| **1** | `']'` | `st.top()` is `'('` $\neq$ `'['` $\rightarrow$ enters `else` | `['(']` | **Returns `false` immediately** |

* **Final Output:** `false`.

## 4. Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$
  * We traverse the string `s` of length $n$ once.
  * Each character is pushed onto and popped from the stack at most once, and all `push`, `pop`, `top`, and `empty` operations execute in $\mathcal{O}(1)$ time.
* **Space Complexity:** $\mathcal{O}(n)$
  * In the worst-case scenario where all characters are opening brackets (e.g., `"((((((("`), all $n$ characters are stored on the stack.

## 5. Edge Cases Handled

1. **Starts with a Closing Bracket (`s = "])"`):**
   * At $i = 0$, `st.empty()` is `true`, safely returning `false` without accessing `st.top()`.
2. **Only Opening Brackets (`s = "((["`):**
   * All characters are pushed onto `st`. At the end, `st.empty()` is `false`, returning `false`.
3. **Single Character String (`s = "("` or `s = "}"`):**
   * Either leaves $1$ item on the stack or triggers `st.empty()`, returning `false` in both cases.
4. **Crossed/Interleaved Brackets (`s = "([)]"`):**
   * At $i = 2$ (`')'`), `st.top()` is `'['`, triggering the mismatch `else` branch and returning `false`.