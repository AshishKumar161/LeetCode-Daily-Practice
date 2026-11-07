# LeetCode 678: Valid Parenthesis String - Detailed Explanation

## 1. Problem Understanding & Core Dilemma

In a standard parenthesis matching problem, a single counter tracks open brackets:
- `'('` adds $+1$
- `')'` subtracts $-1$
- Balance must never become negative, and must end at exactly $0$.

However, in this problem, `'*'` introduces branching paths because it can take one of three roles:
1. An open bracket `'('` ($+1$)
2. A closing bracket `')'` ($-1$)
3. An empty string `""` ($0$)

If we tried to explore every possible choice for each `'*'`, a recursive solution would lead to $O(3^k)$ branching where $k$ is the number of asterisks. We need an optimal, greedy way to keep track of all valid states simultaneously.

---

## 2. Intuition: Range-Based Greedy Tracking

Instead of maintaining a single integer count or generating all branching possibilities, observe that the count of open brackets at any index forms a contiguous interval of possible values:

$$[\text{min\_open}, \text{max\_open}]$$

In your code:
- Variable `a` represents **`min_open`**: The minimum possible number of unmatched `'('` we could have at the current point (by treating `'*'` as `')'` whenever possible).
- Variable `b` represents **`max_open`**: The maximum possible number of unmatched `'('` we could have at the current point (by treating `'*'` as `'('` whenever possible).

### Transition Rules:
1. **Character `'('`:**
   - Both minimum and maximum open bracket counts increment:
     $$a \leftarrow a + 1, \quad b \leftarrow b + 1$$

2. **Character `')'`:**
   - Both minimum and maximum open bracket counts decrement:
     $$a \leftarrow a - 1, \quad b \leftarrow b - 1$$

3. **Character `'*'`:**
   - Worst case for minimum: `'*'` acts as `')'`, decreasing $a$:
     $$a \leftarrow a - 1$$
   - Best case for maximum: `'*'` acts as `'('`, increasing $b$:
     $$b \leftarrow b + 1$$
   - Acting as an empty string `""` falls within the range $[a, b]$.

### Invariant Checks:
- **`b < 0`:** Even in the best-case scenario where every `'*'` acted as `'('`, there are more closing brackets than open ones. The string can never be balanced. Return `false`.
- **`a < 0`:** A negative minimum count implies that we assumed too many `'*'` were `')'`. Since `'*'` can also be an empty string `""`, we clamp `a = 0` so that open counts never drop below zero prematurely.

---

## 3. Step-by-Step Code Walkthrough

```cpp
int a = 0; // min possible open brackets
int b = 0; // max possible open brackets
int n = s.length();

for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
        a++;
        b++;
    } else if (s[i] == ')') {
        a--;
        b--;
    } else { // s[i] == '*'
        a--;
        b++;
    }

    if (b < 0) {
        return false; // unmatched ')' cannot be recovered
    }

    if (a < 0) {
        a = 0; // clamp lower bound at 0
    }
}

return a == 0; // 0 open brackets must be within [a, b]
```

At the end of the loop:
- If `a == 0`, it means having $0$ unmatched open parentheses is achievable within the allowable range $[0, b]$. Hence, the string is valid.

---

## 4. Comprehensive Dry Run

### Test Case 1: `s = "(*))"`

| Step ($i$) | Character `s[i]` | Action on `a` | Action on `b` | Check `b < 0` | Check `a < 0` | Range $[a, b]$ | Notes |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---|
| **Start** | - | $0$ | $0$ | - | - | $[0, 0]$ | Initial state |
| **0** | `'('` | $0 + 1 = 1$ | $0 + 1 = 1$ | No ($1$) | No ($1$) | $[1, 1]$ | Definite open bracket |
| **1** | `'*'` | $1 - 1 = 0$ | $1 + 1 = 2$ | No ($2$) | No ($0$) | $[0, 2]$ | Can be empty, `(`, or `)` |
| **2** | `')'` | $0 - 1 = -1$ | $2 - 1 = 1$ | No ($1$) | Yes $\rightarrow a = 0$ | $[0, 1]$ | $a$ clamped to $0$ |
| **3** | `')'` | $0 - 1 = -1$ | $1 - 1 = 0$ | No ($0$) | Yes $\rightarrow a = 0$ | $[0, 0]$ | $a$ clamped to $0$ |

**Final Check:**
- `a == 0` evaluates to `true` ($0 == 0$).
- Output: `true`.

---

### Test Case 2: `s = ")(*"` (Invalid Case)

| Step ($i$) | Character `s[i]` | Action on `a` | Action on `b` | Check `b < 0` | Check `a < 0` | Result |
|:---:|:---:|:---:|:---:|:---:|:---:|:---|
| **0** | `')'` | $0 - 1 = -1$ | $0 - 1 = -1$ | **Yes** ($b = -1 < 0$) | - | **Returns `false` immediately** |

---

### Test Case 3: `s = "(*"`

| Step ($i$) | Character `s[i]` | $a$ | $b$ | After Clamp $a$ | Range $[a, b]$ |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **0** | `'('` | $1$ | $1$ | $1$ | $[1, 1]$ |
| **1** | `'*'` | $0$ | $2$ | $0$ | $[0, 2]$ |

**Final Check:**
- `a == 0` evaluates to `true`.
- The `'*'` can act as a `')'`, balancing the initial `'('`.

---

## 5. Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$
  - We execute a single pass over the string of length $n$.
  - All conditional updates and bound checks run in $\mathcal{O}(1)$ constant time per character.
  
- **Space Complexity:** $\mathcal{O}(1)$
  - Only two integer scalar variables (`a` and `b`) are used to maintain the active range. No auxiliary arrays, stack data structures, or call stack frames are required.

---

## 6. Edge Cases Handled

1. **Single Asterisk (`s = "*"`):**
   - $a$ becomes $-1 \rightarrow 0$, $b$ becomes $1$. At the end, $a = 0$, returns `true` (acts as empty string).
2. **Trailing Excess Left Brackets (`s = "(((*"`):**
   - $a$ remains greater than $0$ at the end. Returns `false`.
3. **Premature Right Bracket (`s = "())"`):**
   - $b$ becomes negative, correctly exiting early with `false`.